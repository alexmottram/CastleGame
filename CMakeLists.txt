cmake_minimum_required(VERSION 3.10)
project(CastleGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(CastleGame main.cpp CastleGame.cpp CastleGame.h StratergyGenerator.cpp StratergyGenerator.h TestSimulation.cpp TestSimulation.h)