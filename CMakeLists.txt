cmake_minimum_required(VERSION 3.17)

project( VidOpenCV VERSION 0.1.0 LANGUAGES CXX )

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

message("\nConfiguring Precompiled header folder")

add_subdirectory(precompHeader)

message("\nConfiguring TrainImage folder\n")

add_subdirectory(TrainImage)

message("\nConfiguring ImgProc folder\n")

add_subdirectory(ImgProc)

message("\nConfiguring mainProjEx folder\n")

add_subdirectory(mainProjEx)
