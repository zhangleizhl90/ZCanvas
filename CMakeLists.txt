cmake_minimum_required(VERSION 3.0.0)
project(learning VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(doodle
        src/main.cpp
        src/include/Point2D.hpp
        src/include/Rect.hpp
        src/include/QuadTree.hpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
