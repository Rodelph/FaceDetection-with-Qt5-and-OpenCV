add_library(
    Precompiled_H
    precom_Header.h
)

target_include_directories(Precompiled_H PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_precompile_headers(Precompiled_H PUBLIC "precom_Header.h")

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " on this computer !")
    target_link_libraries(Precompiled_H  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " on this computer !")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !")
endif()

find_package(OpenCV REQUIRED)

if(${OpenCV_FOUND})
    message("Found Opencv version " ${OpenCV_VERSION} " on this computer !")
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(Precompiled_H ${OpenCV_LIBS})
    message("Linked Opencv version " ${OpenCV_VERSION} " on this computer !")
elseif(!${OpenCV_FOUND})
    message("Couldn't find an OpenCV installation on this computer !")
endif()
