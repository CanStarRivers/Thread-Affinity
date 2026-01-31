cmake_minimum_required(VERSION 3.10)
project(ThreadAffinity CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -pthread -Wall -Wextra")

# Source files
set(SOURCES
    src/main.cpp
    src/config_loader.cpp
    src/thread_monitor.cpp
    src/affinity_executor.cpp
    src/cpu_topology.cpp
    src/pattern_matcher.cpp
    src/metrics.cpp
)

# Create executable
add_executable(thread-affinity ${SOURCES})

# Link pthread
target_link_libraries(thread-affinity PRIVATE pthread)

# Set output directory
set_target_properties(thread-affinity PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Installation
install(TARGETS thread-affinity DESTINATION bin)
install(FILES config/default.yaml DESTINATION etc/thread-affinity)