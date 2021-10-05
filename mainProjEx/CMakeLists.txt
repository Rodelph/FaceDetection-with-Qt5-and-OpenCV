find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_test(Tester VidOpenCV)

set(CPACK_PROJECT_NAME VidOpenCV)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(VidOpenCV main.cpp)

target_link_libraries(VidOpenCV PRIVATE TrainImage)
target_link_libraries(VidOpenCV PRIVATE Detect)
target_link_libraries(VidOpenCV PRIVATE ImgProc)