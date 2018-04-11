cmake_minimum_required(VERSION 3.1.0)
project(playground)
set(CMAKE_CXX_STANDARD 14)

# add extra include directories
include_directories(/usr/local/include)

# add extra lib directories
link_directories(/usr/local/lib)

# Additional CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)
include(CMakeModules/ParseVersion.cmake)

# Required packages
find_package(dashel REQUIRED)
include_directories(${dashel_INCLUDE_DIRS})

set(enki_DIR /usr/local/Frameworks/enki.framework/Resources/CMake)
find_package(enki REQUIRED)

set(Qt5_DIR /usr/local/Cellar/qt/5.10.1/lib/cmake/Qt5)
find_package(Qt5 COMPONENTS Core Gui Widgets Network Help Multimedia Concurrent Xml Svg Test DBus OpenGL REQUIRED)

# Aseba itself
set(LIB_INSTALL_DIR lib CACHE FILEPATH "Where to install libraries")
set(LIB_VERSION_MAJOR 3) # Must be bumped for incompatible ABI changes
set(LIB_VERSION_MINOR 0)
set(LIB_VERSION_PATCH 0)
set(LIB_VERSION_STRING ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR}.${LIB_VERSION_PATCH})

include_directories(${enki_INCLUDE_DIR})

# Include sub projects
add_subdirectory(common)
add_subdirectory(transport)

# define the core libraries variable, to be used by all Aseba programs
set(ASEBA_CORE_LIBRARIES asebadashelplugins asebacommon ${dashel_LIBRARIES})

# Target and client specific libraries
add_subdirectory(vm)
add_subdirectory(compiler)
add_subdirectory(sim)

find_package(OpenGL REQUIRED)
if (Qt5DBus_FOUND AND NOT WIN32)
	# force disable D-Bus on Windows, because it generates compilation
	# errors in interaction with QtOpenGL includes
	set(EXTRA_LIBS ${EXTRA_LIBS} Qt5::DBus)
	add_definitions("-DHAVE_DBUS")
endif ()
set(CMAKE_AUTOMOC ON)

set(playground_SRCS
	DashelAsebaGlue.cpp
	PlaygroundViewer.cpp
	PlaygroundDBusAdaptors.cpp
	playground.cpp
)

set(ASEBA_CORE_LIBRARIES asebadashelplugins asebacommon ${dashel_LIBRARIES})
add_executable(asebaplayground WIN32 ${playground_SRCS} ${playground_MOCS})
target_link_libraries(asebaplayground asebasim asebavmbuffer asebavm asebazeroconfqt
		${enki_VIEWER_LIBRARIES} ${enki_LIBRARY} ${OPENGL_LIBRARIES}
		Qt5::OpenGL Qt5::Widgets Qt5::Xml ${ASEBA_CORE_LIBRARIES} ${EXTRA_LIBS})
install(TARGETS asebaplayground RUNTIME DESTINATION bin LIBRARY DESTINATION bin)
