cmake_minimum_required(VERSION 3.15)
project(laborat_1)
project(laborat_1_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEAse "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
add_subdirectory(googletest-master)
enable_testing()
include_directories(googletest-master/googletest/include)

add_executable(laborat_1 main.cpp cont.h cont.cpp fish.cpp fish.h bird.cpp
        bird.h animal.cpp animal.h common_animals.cpp common_animals.h)
add_executable(laborat_1_test tests.cpp cont.h cont.cpp fish.cpp fish.h bird.cpp
        bird.h animal.cpp animal.h common_animals.cpp common_animals.h)

target_link_libraries(laborat_1 gtest)
target_link_libraries(laborat_1_test gtest)
