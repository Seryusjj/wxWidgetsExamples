cmake_minimum_required(VERSION 3.0)

project(wxWidgetsExamples)


set(wxWidgets_CONFIGURATION "mswu")
set(OPENGL_LIBRARIES "")
set(GLUT_LIBRARY "")
set(WX_USE_GL 1)
set(BUILD_SHARED_LIBS on)

if(UNIX)
	set(wxWidgets_SELECT_OPTIONS --unicode  --version=3.1 --prefix=/usr)
        find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)
	message(STATUS "Config for unix")
endif()

if(WIN32)
	set(wxWidgets_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets/")  
	set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/vc_dll") 	
	message(STATUS "Config for win32")
endif()


find_package(wxWidgets COMPONENTS xrc stc richtext ribbon propgrid aui gl html qa adv core xml net base REQUIRED)



if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${wxWidgets_CXX_FLAGS}")
    message(STATUS "CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()


if (MSVC)
  set (CMAKE_CXX_FLAGS "/MT /DWIN32 /D_WINDOWS /W3 /GR /Zi /EHsc")
  set (CMAKE_CXX_FLAGS_DEBUG "/EHsc /D_DEBUG /MTd /Ob0 /Od")
  set (CMAKE_CXX_FLAGS_RELEASE "/EHsc /MT /Ox /Ob2 /Oi /Ot /Oy /GL /DNDEBUG")
endif ()





add_subdirectory(src)

