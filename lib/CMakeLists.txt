add_library(kozmic STATIC "window/Window.cpp" "window/_win32/Win32Window.cpp")
set_property(TARGET kozmic PROPERTY CXX_STANDARD 17)

target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/lib")