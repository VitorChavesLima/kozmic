set(SPDLOG_HEADERS_DIRECTORY)
set(SPDLOG_LIB_DIRECTORY)

message("SPDLOG HEADERS DIRECTORY: ${SPDLOG_HEADERS_DIRECTORY}")
message("SPDLOG LIB DIRECTORY: ${SPDLOG_LIB_DIRECTORY}")

add_library(kozmic STATIC "window/Window.cpp" "window/_win32/Win32Window.cpp" "window/WindowManager.cpp"   "input/_win32/Win32KeyMapper.cpp"   "input/_win32/Win32Keyboard.cpp" "input/Keyboard.cpp" "input/KeyMap.cpp" "input/Mouse.cpp" "input/_win32/Win32Mouse.cpp" "logging/Logger.cpp" "logging/LoggerGenerator.cpp" "logging/LoggingManager.cpp" "Application.cpp" "utils/Exception.cpp" "graphics/_directx11/DX11Graphics.cpp")
set_property(TARGET kozmic PROPERTY CXX_STANDARD 17)

target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/include" "${SPDLOG_HEADERS_DIRECTORY}")
target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/lib")
target_link_directories(kozmic PUBLIC "${SPDLOG_LIB_DIRECTORY}")
target_link_libraries(kozmic spdlogd d3d11)