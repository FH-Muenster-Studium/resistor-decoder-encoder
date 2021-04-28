cmake_minimum_required(VERSION 3.17)
project(praktikum_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(praktikum_1 main.cpp resistor.cpp resistor.hpp decoder.cpp decoder.hpp encoder.cpp encoder.hpp color.hpp multiplier_color.hpp temperature_coefficient_color.hpp tolerance_color.hpp)