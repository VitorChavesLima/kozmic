add_executable(demo "main.cpp" "Game.cpp")
set_property(TARGET demo PROPERTY CXX_STANDARD 17)

target_include_directories(demo PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(demo kozmic)