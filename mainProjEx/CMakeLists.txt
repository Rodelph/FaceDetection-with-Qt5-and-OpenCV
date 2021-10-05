find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_executable(VidOpenCV main.cpp)

target_link_libraries(VidOpenCV PRIVATE TrainImage)
target_link_libraries(VidOpenCV PRIVATE Detect)
target_link_libraries(VidOpenCV PRIVATE ImgProc)

message("All libraries have been linked !")