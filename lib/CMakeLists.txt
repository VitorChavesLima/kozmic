set(SPDLOG_HEADERS_DIRECTORY)
set(SPDLOG_LIB_DIRECTORY)

message("SPDLOG HEADERS DIRECTORY: ${SPDLOG_HEADERS_DIRECTORY}")
message("SPDLOG LIB DIRECTORY: ${SPDLOG_LIB_DIRECTORY}")

add_library(kozmic STATIC "core/window/WindowController.cpp" "core/window/_win32/Win32WindowController.cpp" "core/window/WindowManager.cpp"   "core/input/_win32/Win32KeyMapper.cpp"   "core/input/_win32/Win32Keyboard.cpp" "core/input/Keyboard.cpp" "core/input/KeyMap.cpp" "core/input/Mouse.cpp" "core/input/_win32/Win32Mouse.cpp" "core/logging/Logger.cpp" "core/logging/LoggerGenerator.cpp" "core/logging/LoggingManager.cpp"  "core/utils/Exception.cpp" "core/graphics/_directx11/DX11GraphicsController.cpp"  "core/utils/Controller.cpp" core/graphics/_directx11/DX11ShaderController.cpp core/graphics/_directx11/shader/DX11CompiledShaderData.cpp core/graphics/_directx11/shader/DX11Shader.cpp core/graphics/_directx11/shader/DX11ShaderInputLayout.cpp core/graphics/_directx11/DX11MeshController.cpp core/graphics/_directx11/mesh/DX11StaticMesh.cpp)
set_property(TARGET kozmic PROPERTY CXX_STANDARD 17)

target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/include" "${SPDLOG_HEADERS_DIRECTORY}")
target_include_directories(kozmic PUBLIC "${CMAKE_SOURCE_DIR}/lib")
target_link_directories(kozmic PUBLIC "${SPDLOG_LIB_DIRECTORY}")
target_link_libraries(kozmic spdlog d3d11 d3dcompiler)