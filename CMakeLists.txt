cmake_minimum_required(VERSION 3.8)

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

include(CTest)

add_subdirectory(TrainImage)

add_subdirectory(ImgProc)

add_subdirectory(mainProjEx)

enable_testing()