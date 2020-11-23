cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp)
aux_source_directory(src/main/cpp SRC_task)
aux_source_directory(src/main/cpp/sample SRC_demos)

add_library(
        taskcore
        STATIC
        ${SRC_task}
)

add_library(
        jnitest
        SHARED
        ${SRC_demos}
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries(
        jnitest
        taskcore
        ${log-lib}
)