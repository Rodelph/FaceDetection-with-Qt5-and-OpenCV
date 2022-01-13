find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(VidOpenCV main.cpp)

set(HEADER_FILES ../precompHeader/preH.h)

target_precompile_headers(VidOpenCV PRIVATE ${HEADER_FILES})

target_link_libraries(VidOpenCV PRIVATE InfoOnApp)
target_link_libraries(VidOpenCV PRIVATE ImgProc)

message("All libraries have been linked !")
