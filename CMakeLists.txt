cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(libdisney)

# Thanks to loblao's libpandadna for the base interrogate CMake project

find_package (Python2 COMPONENTS Interpreter Development)
if(NOT Python2_Development_FOUND)
    message(FATAL_ERROR "Python libs not found.")
endif()
if(NOT Python2_Interpreter_FOUND)
    message(FATAL_ERROR "Python interpreter not found.")
endif()

### Panda3D dir ###
if(APPLE)
    SET(PANDA_DIR "/Developer/Panda3D" CACHE STRING "Panda3D directory.")
endif()
if(WIN32)
    SET(PANDA_DIR "C:/Panda3D-1.11.0-old" CACHE STRING "Panda3D directory.")
endif()
SET(BUILD_STATIC_LIB OFF CACHE BOOL "If true, will build a static lib")

set(LIBPFX "")
if(MSVC)
    set(LIBPFX "lib")
    add_definitions(/wd4275)
    add_definitions(/DYY_NO_UNISTD_H)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    message(STATUS "GCC Version: ${GCC_VERSION}")
    if(GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        add_definitions(-std=c++11) # Enable the new C++ standard
    else()
        add_definitions(-std=c++0x) # Enable the new C++ standard
    endif()

    add_definitions(-Wno-ignored-attributes -Wno-deprecated-declarations -Wno-misleading-indentation)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" -dumpversion OUTPUT_VARIABLE CLANG_VERSION)
    message(STATUS "Clang Version: ${CLANG_VERSION}")
    add_definitions(-std=c++11) # Enable the new C++ standard
    add_definitions(-Wno-ignored-attributes -Wno-deprecated-declarations)
endif()

add_subdirectory(cmake/otp)
add_subdirectory(cmake/toontown)