cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(libtoontown)

### Define core components ###
set(DNA_FILES
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/config_dna.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/config_dna.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaAnimBuilding.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaAnimBuilding.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaAnimProp.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaAnimProp.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaBattleCell.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaBattleCell.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaBuildings.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaBuildings.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaConstants.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaCornice.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaCornice.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaData.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaData.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaDoor.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaDoor.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaGroup.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaGroup.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaInteractiveProp.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaInteractiveProp.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaLoader.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaLoader.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaNode.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaNode.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaProp.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaProp.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSign.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSign.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignBaseline.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignBaseline.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignGraphic.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignGraphic.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignText.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSignText.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaStorage.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaStorage.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaStreet.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaStreet.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitEdge.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitEdge.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitPath.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitPath.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitPoint.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaSuitPoint.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaVisGroup.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaVisGroup.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaWindow.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/dnaWindow.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/lexerDefs.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/load_dna_file.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/load_dna_file.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/loaderFileTypeDNA.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/loaderFileTypeDNA.h
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/lexer.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/parser.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/dna/parser.hxx
)
set(PET_FILES
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cImpulse.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cImpulse.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMover.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMover.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMoverGroup.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/cMoverGroup.h
    ${CMAKE_SOURCE_DIR}/src/otp/movement/config_movement.cxx
    ${CMAKE_SOURCE_DIR}/src/otp/movement/config_movement.h
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetBrain.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetBrain.h
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetChase.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetChase.h
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetFlee.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/cPetFlee.h
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/config_pets.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/pets/config_pets.h
)
set(SUIT_FILES
    ${CMAKE_SOURCE_DIR}/src/toontown/suit/suitLeg.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/suit/suitLeg.h
    ${CMAKE_SOURCE_DIR}/src/toontown/suit/suitLegList.cxx
    ${CMAKE_SOURCE_DIR}/src/toontown/suit/suitLegList.h
)
set(TT_IGATE_FILES
    ${CMAKE_SOURCE_DIR}/src/toontown_igate.cxx
    ${CMAKE_SOURCE_DIR}/src/libtoontown_module.cxx
)

set_property(SOURCE ${TT_IGATE_FILES} PROPERTY GENERATED TRUE)

include_directories(${CMAKE_SOURCE_DIR}/src/toontown/dna)
include_directories(${CMAKE_SOURCE_DIR}/src/toontown/pets)
include_directories(${CMAKE_SOURCE_DIR}/src/toontown/suit)
include_directories(${CMAKE_SOURCE_DIR}/src/toontown/toontownbase)
include_directories(${CMAKE_SOURCE_DIR}/src/otp/movement)
include_directories(${CMAKE_SOURCE_DIR}/src/otp/otpbase)
include_directories(${PANDA_DIR}/include)
include_directories(${Python_INCLUDE_DIRS})
include_directories(/usr/include/eigen3)
link_directories(${PANDA_DIR}/lib)

add_definitions(-DBUILDING_TOONTOWN)

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
        add_library(libtoontown SHARED
            ${DNA_FILES}
            ${PET_FILES}
            ${SUIT_FILES}
            ${TT_IGATE_FILES}
        )
        SET_TARGET_PROPERTIES(libtoontown PROPERTIES SUFFIX ".pyd")
        target_link_libraries(libtoontown ${PANDA_LIBS} "${Python_LIBRARIES}")

    else()
        add_library(toontown MODULE
            ${DNA_FILES}
            ${PET_FILES}
            ${SUIT_FILES}
            ${TT_IGATE_FILES}
        )
        target_link_libraries(toontown ${PANDA_LIBS} "${Python_LIBRARIES}")
    endif()

else()

    if(WIN32)
        add_library(libtoontown STATIC
            ${DNA_FILES}
            ${PET_FILES}
            ${SUIT_FILES}
            ${TT_IGATE_FILES}
        )

    else()
        add_library(toontown STATIC
            ${DNA_FILES}
            ${PET_FILES}
            ${SUIT_FILES}
            ${TT_IGATE_FILES}
        )
    endif()

endif()

### Setup source groups and defines for configurables ###
source_group("dna" FILES ${DNA_FILES})
source_group("pet" FILES ${PET_FILES})
source_group("suit" FILES ${SUIT_FILES})
source_group("tt_interrogate_files" FILES ${TT_IGATE_FILES})
