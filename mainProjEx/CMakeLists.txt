find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(VidOpenCV main.cpp)

target_link_libraries(VidOpenCV PRIVATE TrainImage)
target_link_libraries(VidOpenCV PRIVATE ImgProc)
target_link_libraries(VidOpenCV PRIVATE Precompiled_H)

message("All libraries have been linked !")
