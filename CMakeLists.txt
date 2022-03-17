cmake_minimum_required(VERSION 3.20)
project(basic_file_processing_cstring)

set(CMAKE_CXX_STANDARD 14)

add_executable(file-processing main.cpp Formatting.cpp Formatting.h FileProcessing.cpp FileProcessing.h)
