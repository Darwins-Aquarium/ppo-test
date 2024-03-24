cmake_minimum_required(VERSION 3.28)
project(ppo_test)
set(CMAKE_CXX_STANDARD 17)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
add_executable(ppo_test main.cpp
        Game.cpp
        Game.h
        Network.cpp
        Network.h
        PPO.cpp
        PPO.h
        PPO.cpp
        MultivariateNormal.cpp
        MultivariateNormal.h)
target_link_libraries(ppo_test "${TORCH_LIBRARIES}")
set_property(TARGET ppo_test PROPERTY CXX_STANDARD 17)