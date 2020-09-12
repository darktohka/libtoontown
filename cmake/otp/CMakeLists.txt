cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(libotp)

### Define core components ###
set(MOVEMENT_FILES
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cImpulse.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cImpulse.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMover.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMover.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMoverGroup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMoverGroup.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/config_movement.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/config_movement.h
)
set(NAMETAG_FILES
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/chatBalloon.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/chatBalloon.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/chatFlags.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/clickablePopup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/clickablePopup.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/config_nametag.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/config_nametag.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/marginManager.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/marginManager.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/marginPopup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/marginPopup.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag2d.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag2d.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag3d.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametag3d.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagFloat2d.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagFloat2d.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagFloat3d.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagFloat3d.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagGlobals.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagGlobals.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagGroup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/nametagGroup.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/popupMouseWatcherRegion.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/popupMouseWatcherRegion.h
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/whisperPopup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/nametag/whisperPopup.h
)

set(NAVIGATION_FILES
    ${CMAKE_SOURCE_DIR}/src/otp/navigation/pathTable.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/navigation/pathTable.h
)

set(OTP_IGATE_FILES
    ${CMAKE_SOURCE_DIR}/src/otp_igate.cxx
    ${CMAKE_SOURCE_DIR}/src/libotp_module.cxx
)

include_directories(${CMAKE_SOURCE_DIR}/src/otp/nametag)
include_directories(${CMAKE_SOURCE_DIR}/src/otp/movement)
include_directories(${CMAKE_SOURCE_DIR}/src/otp/navigation)
include_directories(${CMAKE_SOURCE_DIR}/src/otp/otpbase)
include_directories(${PANDA_DIR}/include)
include_directories(${Python2_INCLUDE_DIRS})
include_directories(/usr/include/eigen3)
link_directories(${PANDA_DIR}/lib)

if(NOT BUILD_STATIC_LIB)
    set(PANDA_LIBS
        ${LIBPFX}p3framework
        ${LIBPFX}panda
        ${LIBPFX}pandafx
        ${LIBPFX}pandaexpress
        ${LIBPFX}p3dtool
        ${LIBPFX}p3dtoolconfig
        ${LIBPFX}p3direct
    )

    # Add p3interrogatedb, if it exists
    find_library(HAVE_P3INTERROGATEDB
                 ${LIBPFX}p3interrogatedb
                 HINTS ${PANDA_DIR}/lib)

    if(HAVE_P3INTERROGATEDB)
        message(STATUS "libp3interrogatedb found")
        LIST(APPEND PANDA_LIBS ${LIBPFX}p3interrogatedb)
    else()
        message(STATUS "libp3interrogatedb not found")
    endif()

    # Add p3pandatoolbase, if it exists
    find_library(HAVE_P3PANDATOOLBASE
                 ${LIBPFX}p3pandatoolbase
                 HINTS ${PANDA_DIR}/lib)

    if(HAVE_P3PANDATOOLBASE)
        message(STATUS "libp3pandatoolbase found")
        LIST(APPEND PANDA_LIBS ${LIBPFX}p3pandatoolbase)
    else()
        message(STATUS "libp3pandatoolbase not found")
    endif()

    if(WIN32)
        add_library(libotp SHARED
            ${MOVEMENT_FILES}
            ${NAMETAG_FILES}
            ${NAVIGATION_FILES}
            ${OTP_IGATE_FILES}
        )
        SET_TARGET_PROPERTIES(libotp PROPERTIES SUFFIX ".pyd")
        target_link_libraries(libotp ${PANDA_LIBS} C:/Panda3D-1.11.0-old/python/libs/python27.lib)
        add_custom_command(TARGET libotp
                           PRE_BUILD
                           COMMAND ${Python2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(otp MODULE
            ${MOVEMENT_FILES}
            ${NAMETAG_FILES}
            ${NAVIGATION_FILES}
            ${OTP_IGATE_FILES}
        )
        target_link_libraries(otp ${PANDA_LIBS} ${PYTHON2_LIBRARIES})
        add_custom_command(TARGET otp
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

else()

    if(WIN32)
        add_library(libotp STATIC
            ${MOVEMENT_FILES}
            ${NAMETAG_FILES}
            ${NAVIGATION_FILES}
            ${OTP_IGATE_FILES}
        )
        add_custom_command(TARGET libotp
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(otp STATIC
            ${MOVEMENT_FILES}
            ${NAMETAG_FILES}
            ${NAVIGATION_FILES}
            ${OTP_IGATE_FILES}
        )
        add_custom_command(TARGET pandadna
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

endif()

### Setup source groups and defines for configurables ###
source_group("movement" FILES ${MOVEMENT_FILES})
source_group("nametag" FILES ${NAMETAG_FILES})
source_group("navigation" FILES ${NAVIGATION_FILES})
source_group("otp_interrogate_files" FILES ${OTP_IGATE_FILES})