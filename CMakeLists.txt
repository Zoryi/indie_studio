##
## EPITECH PROJECT, 2018
## CMakeLists
## File description:
## CMakeLists
##
cmake_minimum_required(VERSION 3.7)

project(bomberman)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread -lGL -lXxf86vm")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
       set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)

if(CMAKE_CXX_FLAGS_DEBUG)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/indie)
else(CMAKE_CXX_FLAGS_DEBUG)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/indie)
endif(CMAKE_CXX_FLAGS_DEBUG)

FIND_PACKAGE(X11)
FIND_PACKAGE(OpenGL)
FIND_PACKAGE(Threads)
FIND_PACKAGE(ZLIB)

set(IRRKLANG_HOME "${CMAKE_CURRENT_SOURCE_DIR}/lib/IrrKlang")
set(IRRKLANG_INCLUDE_DIR "${IRRKLANG_HOME}/include")
set(IRRKLANG_LIBRARIES "${IRRKLANG_HOME}/libIrrKlang.so")

set(IRRLICHT_HOME "${CMAKE_CURRENT_SOURCE_DIR}/lib/irrlicht")
set(IRRLICHT_INCLUDE_DIR "${IRRLICHT_HOME}/include")
set(IRRLICHT_LIBRARIES "${IRRLICHT_HOME}/libIrrlicht.a")

include_directories(
	${X11_INCLUDE_DIR}
	${OpenGL_INCLUDE_DIR}
	${Threads_INCLUDE_DIR}
	${ZLIB_INCLUDE_DIR}
	${IRRKLANG_INCLUDE_DIR}
	${IRRLICHT_INCLUDE_DIR}
)

set(bomberman_SOURCES
	indie/Main.cpp
	indie/Core.cpp
	indie/IndieWindow.cpp
	indie/IndieRendering.cpp
	indie/IndieEventReceiver.cpp
	indie/GraphObj.cpp
	indie/GraphNb.cpp
	indie/Map.cpp
	indie/Info3d.cpp
	indie/Menu.cpp
	indie/UI.cpp
	indie/Sound.cpp
	indie/object/Block.cpp
	indie/object/Bomb.cpp
	indie/object/BombUp.cpp
	indie/object/FireUp.cpp
	indie/object/SpeedUp.cpp
	indie/object/WallPass.cpp
	indie/character/BasicPlayer.cpp
	indie/character/NPC.cpp
	indie/character/PC.cpp
	indie/animation/AnimFireExplo.cpp
)

add_executable(bomberman ${bomberman_SOURCES} ${HEADER_FILES})

include_directories(bomberman
	indie
	indie/object/
	indie/character/
	indie/animation/
)

add_library(Irrlicht STATIC IMPORTED)
add_library(IrrKlang STATIC IMPORTED)

target_link_libraries(bomberman
	${X11_LIBRARIES}
	${OpenGL_LIBRARIES}
	${Threads_LIBRARIES}
	${ZLIB_LIBRARIES}
	${IRRKLANG_LIBRARIES}
	${IRRLICHT_LIBRARIES}
)
