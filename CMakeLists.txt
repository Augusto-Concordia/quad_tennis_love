cmake_minimum_required(VERSION 3.20)
project(quad_tennis_love)

set(CMAKE_CXX_STANDARD 20)

IF (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
ENDIF()


# finds our own OpenGL dependency from installed binaries
find_package(OpenGL REQUIRED)

# includes vendors' source CMake projects
add_subdirectory(vendor)

# add s_engine project and link glfw to it
file(GLOB_RECURSE QUAD_TENNIS_LOVE_FILES source/**.cpp)
add_executable(quad_tennis_love ${QUAD_TENNIS_LOVE_FILES})

target_include_directories(quad_tennis_love PRIVATE source)
target_link_libraries(quad_tennis_love PRIVATE glfw OpenGL::GL glm glad -static-libgcc -static-libstdc++)