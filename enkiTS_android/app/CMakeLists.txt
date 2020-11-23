cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp)
include_directories(src/main/cpp/include)
aux_source_directory(src/main/cpp SRC_task)
aux_source_directory(src/main/cpp/sample SRC_demos)
#aux_source_directory(src/main/cpp/timer SRC_timer)

add_library(
        taskcore
        STATIC
        ${SRC_task}
)

add_library(
        timer
        STATIC
        src/main/cpp/system_wrappers/source/event.cc
        src/main/cpp/system_wrappers/source/event_posix.cc
        src/main/cpp/system_wrappers/source/thread.cc
        src/main/cpp/system_wrappers/source/thread_posix.cc
        src/main/cpp/system_wrappers/source/timer.cc
        src/main/cpp/system_wrappers/source/timer_posix.cc
        src/main/cpp/system_wrappers/source/critical_section.cc
        src/main/cpp/system_wrappers/source/critical_section_posix.cc
        src/main/cpp/system_wrappers/source/trace_impl.cc
        src/main/cpp/system_wrappers/source/trace_posix.cc
        src/main/cpp/system_wrappers/source/logcat_trace_context.cc
        src/main/cpp/system_wrappers/source/file_impl.cc
        src/main/cpp/system_wrappers/source/logging.cc
        src/main/cpp/system_wrappers/source/rw_lock.cc
        src/main/cpp/system_wrappers/source/rw_lock_generic.cc
        src/main/cpp/system_wrappers/source/rw_lock_posix.cc
        src/main/cpp/system_wrappers/source/sleep.cc
        src/main/cpp/modules/LogModule/log_module.cpp
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
        timer
        ${log-lib}
)