add_library(
	Detect
	src/detect.cpp
	src/detect.ui
	src/Header/detect.h
)

target_include_directories(Detect PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt version : " ${Qt5_VERSION} " on this computer !")
    target_link_libraries(Detect  Qt5::Widgets Qt5::Core Qt5::Gui)
    message("Linked Qt version : " ${Qt5_VERSION} " on this computer !")
elseif(!${Qt5_FOUND})
    message("Coudn't find a Qt installation on this computer !")
endif()

find_package(Boost REQUIRED)

if(${Boost_FOUND})
    message("Found Boost version " ${Boost_VERSION} " on this computer !")
    include_directories( ${Boost_INCLUDE_DIR} )
    target_link_libraries(Detect ${Boost_LIBRARIES} )
    message("Linked Boost version " ${Boost_VERSION} " on this computer !")
elseif(!${Boost_FOUND})
    message("Couldn't find a Boost installation on this computer !")
endif()

find_package(OpenCV REQUIRED)

if(${OpenCV_FOUND})
    message("Found Opencv version " ${OpenCV_VERSION} " on this computer !")
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(Detect ${OpenCV_LIBS})
    message("Linked Opencv version " ${OpenCV_VERSION} " on this computer !")
elseif(!${OpenCV_FOUND})
    message("Couldn't find an OpenCV installation on this computer !")
endif()