cmake_minimum_required(VERSION 3.10)
project(Fase4)

set(CMAKE_CXX_STANDARD 14)

if  (WIN32)

else(WIN32) #Linux and Mac
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    find_package(GLEW REQUIRED)
endif(WIN32)

add_executable(engine src/Engine/engine.cpp)
add_executable(generator src/Generator/generator.cpp)

add_library(
        Lib
        src/tinyXML/tinystr.cpp
        src/tinyXML/tinyxml.cpp
        src/tinyXML/tinyxmlerror.cpp
        src/tinyXML/tinyxmlparser.cpp
)

add_library(
        engineLib
        src/Engine/drawFunctions.cpp
        src/Engine/drawFunctions.hpp
        src/Engine/catmullRom.cpp
        src/Engine/catmullRom.hpp
)

add_library(
        generatorLib
        src/Generator/vertices.cpp
        src/Generator/vertices.hpp
)

add_library(
        structsLib
        src/Structs/structs.cpp
        src/Structs/structs.hpp
)

add_library(
        matricesLib
        src/Matrices/matrices.cpp
        src/Matrices/matrices.hpp
)

target_link_libraries(generator generatorLib)
target_link_libraries(generator Lib)
target_link_libraries(generator structsLib)
target_link_libraries(generator matricesLib)

target_link_libraries(engine engineLib)
target_link_libraries(engine Lib)
target_link_libraries(engine structsLib)
target_link_libraries(engine matricesLib)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

    message(STATUS "Toolkits_DIR set to: " ${TOOLKITS_FOLDER})
    set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

    if (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
        message(ERROR ": GLUT not found")
    endif (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")

    if (NOT EXISTS "${TOOLKITS_FOLDER}/glew/GL/glew.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glew/glew32.lib")
        message(ERROR ": GLEW not found")
    endif (NOT EXISTS "${TOOLKITS_FOLDER}/glew/GL/glew.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glew/glew32.lib")

    if (NOT EXISTS "${TOOLKITS_FOLDER}/devil/IL/il.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/devil/devIL.lib")
        message(ERROR ": DevIL not found")
    endif (NOT EXISTS "${TOOLKITS_FOLDER}/devil/IL/il.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/devil/devIL.lib")

    include_directories(${TOOLKITS_FOLDER}/glut ${TOOLKITS_FOLDER}/glew ${TOOLKITS_FOLDER}/devil)
    target_link_libraries(motor ${OPENGL_LIBRARIES}
            ${TOOLKITS_FOLDER}/glut/glut32.lib
            ${TOOLKITS_FOLDER}/devil/devIL.lib
            ${TOOLKITS_FOLDER}/glew/glew32.lib )

    if (EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" AND EXISTS "${TOOLKITS_FOLDER}/glew/glew32.dll"
            AND EXISTS "${TOOLKITS_FOLDER}/devil/devil.dll")
        file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
        file(COPY ${TOOLKITS_FOLDER}/devil/devil.dll DESTINATION ${CMAKE_BINARY_DIR})
        file(COPY ${TOOLKITS_FOLDER}/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
    endif(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" AND EXISTS "${TOOLKITS_FOLDER}/glew/glew32.dll"
            AND EXISTS "${TOOLKITS_FOLDER}/devil/devil.dll")

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT motor)

else (WIN32) #Linux and Mac

    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")

    find_package(GLUT REQUIRED)
    include_directories(${GLUT_INCLUDE_DIR})
    link_directories(${GLUT_LIBRARY_DIRS})
    add_definitions(${GLUT_DEFINITIONS})

    if (NOT APPLE)
        find_package(GLEW REQUIRED)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
        target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})
    else (NOT APPLE)
        target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} )
    endif(NOT APPLE)

    target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} )
    if(NOT GLUT_FOUND)
        message(ERROR ": GLUT not found!")
    endif(NOT GLUT_FOUND)

endif(WIN32)