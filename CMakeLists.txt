cmake_minimum_required(VERSION 3.0)
project(EXray)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# File globbing
file(GLOB_RECURSE sources "src/*.hpp" "src/*.cpp")
file(GLOB_RECURSE resources "resources/*")

# Compilation
add_executable(exray ${sources})
target_compile_options(exray PUBLIC -Wall -Wextra -pedantic)
target_link_libraries(exray PRIVATE Threads::Threads)

# Copy all resource files to the build directory
file(COPY ${resources} DESTINATION resources)