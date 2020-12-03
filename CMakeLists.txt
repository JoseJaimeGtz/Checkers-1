#
# CMakeLists.txt configura lo que necesitas para poder correr el proyecto, tanto como los archivos .c, como la
# instalación de raylib (Librería gráfica)
#
cmake_minimum_required(VERSION 3.18)
project(Checkers C)
set(CMAKE_C_STANDARD 99)

# Set this to the minimal version you want to support

# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        # build raylib
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

    endif()

endif()

add_executable(Checkers graphics.c gameLogic.c game.c main.c)
target_link_libraries(Checkers raylib)
