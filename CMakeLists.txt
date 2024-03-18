cmake_minimum_required(VERSION 3.28)
project(ppo_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(ppo_test main.cpp
        Game.cpp
        Game.h)
