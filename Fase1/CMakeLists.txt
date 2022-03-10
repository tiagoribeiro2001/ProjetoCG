cmake_minimum_required(VERSION 3.10)
project(Fase1)

set(CMAKE_CXX_STANDARD 14)

if  (WIN32)

else(WIN32) #Linux and Mac
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
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

target_link_libraries(generator generatorLib)
target_link_libraries(generator Lib)
target_link_libraries(generator structsLib)

target_link_libraries(engine engineLib)
target_link_libraries(engine Lib)
target_link_libraries(engine structsLib)




if  (WIN32)

    find_package(OpenGL REQUIRED)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})

    if(NOT OPENGL_FOUND)
        message(ERROR " OPENGL not found!")
    endif(NOT OPENGL_FOUND)

    message(STATUS "Toolkits_DIR set to: " ${TOOLKITS_FOLDER})
    set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

    if (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
        message(ERROR ": GLUT not found")
    endif (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")


    include_directories(${TOOLKITS_FOLDER}/glut )
    target_link_libraries(engine ${OPENGL_LIBRARIES}
            ${TOOLKITS_FOLDER}/glut/glut32.lib)

    if (EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )
        file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
    endif(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT motor)

else (WIN32) #Linux and Mac
    target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif(WIN32)