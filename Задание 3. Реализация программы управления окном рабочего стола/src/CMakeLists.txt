add_executable ("practic_work" "main.cpp" "../include/monitor.h" "monitor.cpp" "../include/window.h" "window.cpp")

target_include_directories("practic_work" PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)