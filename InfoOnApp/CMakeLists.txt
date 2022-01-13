add_library(
    InfoOnApp
    src/Header/infoapp.h
    src/infoapp.cpp
    src/infoapp.ui
)

target_include_directories(InfoOnApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " on this computer !\n")
    target_link_libraries(InfoOnApp  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " on this computer !\n")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !\n")
endif()

find_package(OpenCV REQUIRED)

if(${OpenCV_FOUND})
    message("Found Opencv version :" ${OpenCV_VERSION} " on this computer !\n")
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(InfoOnApp ${OpenCV_LIBS})
    message("Linked Opencv version :" ${OpenCV_VERSION} " on this computer !\n")
elseif(!${OpenCV_FOUND})
    message("Couldn't find an OpenCV installation on this computer !\n")
endif()
