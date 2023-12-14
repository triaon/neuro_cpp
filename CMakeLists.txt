cmake_minimum_required(VERSION 3.26)
project(untitled)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_executable(mainneuro
        main.cpp
        CWidget.cpp
        ConvolutionalLayer.cpp
        poolLayer.cpp
        ConnectLayers.cpp
)

target_link_libraries(mainneuro Qt5::Widgets)
