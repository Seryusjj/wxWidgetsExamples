cmake_minimum_required(VERSION 3.0)

project(wxWidgetsExamples)


set(wxWidgets_CONFIGURATION "mswu")
SET(wxWidgets_USE_STATIC off)
set(OPENGL_LIBRARIES "")
set(GLUT_LIBRARY "")

if(UNIX)
	set(wxWidgets_USE_RELEASE --toolkit=base --prefix=/usr)
        find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)
	message(STATUS "Config for unix")
endif()

if(WIN32)
	set(wxWidgets_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets/")  
	set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/vc_dll") 	
	message(STATUS "Config for win32")
endif()


set(WX_USE_GL on)
find_package(wxWidgets COMPONENTS gl core base REQUIRED)


if(UNIX)
    add_definitions(-std=c++11)
    set(CMAKE_CXX_FLAGS "${wxWidgets_CXX_FLAGS}")
endif()


if (MSVC)
  set (CMAKE_CXX_FLAGS "/MT /DWIN32 /D_WINDOWS /W3 /GR /Zi /EHsc")
  set (CMAKE_CXX_FLAGS_DEBUG "/EHsc /D_DEBUG /MTd /Ob0 /Od")
  set (CMAKE_CXX_FLAGS_RELEASE "/EHsc /MT /Ox /Ob2 /Oi /Ot /Oy /GL /DNDEBUG")
endif ()





add_subdirectory(src)

