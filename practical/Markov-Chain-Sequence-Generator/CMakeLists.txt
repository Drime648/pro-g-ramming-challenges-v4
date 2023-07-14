cmake_minimum_required(VERSION 3.25)
project(Markov_Chain_Sequence_Generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Markov_Chain_Sequence_Generator main.cpp MarkovModel.cpp MarkovModel.h)
