import subprocess
import glob
import sys
import os

srcdir = os.path.abspath(os.path.dirname(__file__))
pandadir = os.path.abspath(sys.argv[1])

def run_command(cmd):
    p = subprocess.Popen(cmd, stdout=sys.stdout, stderr=sys.stderr, shell=True)
    ret = p.wait()

    if ret != 0:
        print()
        print('The following command return a non-zero value (%d): %s' % (ret, cmd))
        sys.exit(ret)

def interrogate(module, extra_includes=[]):
    print('Interrogating', module)
    cmd = os.path.join(pandadir, 'bin', 'interrogate')
    cmd += ' -D__inline -DCPPPARSER -DP3_INTERROGATE=1 -D__cplusplus -fnames -string -refcount -assert'
    cmd += ' -S"%(pandadir)s/include/parser-inc" -S"%(pandadir)s/include" -I"%(pandadir)s/include"'
    cmd += ' -srcdir "%(srcdir)s/%(module)s" -oc "%(srcdir)s/%(module)s_igate.cxx" -od "%(srcdir)s/%(module)s.in" -python-native -DCPPPARSER -D__STDC__=1'
    cmd += ' -D__cplusplus -D__inline -D_X86_ -DWIN32_VC -DWIN32 -module lib%(module)s -library %(module)s -Dvolatile='
    cmd = cmd % {'pandadir': pandadir, 'module': module, 'srcdir': srcdir}

    moduledir = os.path.join(srcdir, module)

    for module in os.listdir(moduledir):
        cmd += ' -I"{0}"'.format(os.path.join(moduledir, module))

    for extra_include in extra_includes:
        cmd += ' -I"{0}"'.format(os.path.join(srcdir, extra_include))

    files = glob.glob(os.path.join(moduledir, '**/*.h'))

    for file in files:
        cmd += ' %s' % file

    print(cmd)
    run_command(cmd)

def interrogate_module(module):
    cmd = os.path.join(pandadir, 'bin', 'interrogate_module') + ' -python-native -oc lib%(module)s_module.cxx'
    cmd += ' -library lib%(module)s -module lib%(module)s %(module)s.in'
    cmd = cmd % {'module': module}
    run_command(cmd)

os.chdir(srcdir)

interrogate('otp')
interrogate_module('otp')

interrogate('toontown', extra_includes=[os.path.join('otp', 'movement'), os.path.join('otp', 'otpbase')])
interrogate_module('toontown')