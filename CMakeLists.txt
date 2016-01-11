cmake_minimum_required(VERSION 2.8.8)
project(holiday)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

####### EDIT LINE BELOW #######
set(CMAKE_PREFIX_PATH /opt/Qt/5.5/gcc_64/) # SET YOUR QT5 INSTALLATION PATH (/bin, /include, /lib, ETC.)

find_package(Qt5Core REQUIRED)

set(SOURCES src/Holiday.cpp
            src/HolidayPackage.cpp
            src/HolidayPackageExtractor.cpp
            src/HolidayPackageManager.cpp
            src/HolidayOutputer.cpp)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/packages DESTINATION lib/${PROJECT_NAME})
