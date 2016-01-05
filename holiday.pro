QT += core
QT -= gui

CONFIG += c++11

TARGET = holiday
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    HolidayPackageManager.cpp \
    Holiday.cpp \
    HolidayPackage.cpp \
    HolidayPackageExtractor.cpp \
    HolidayOutputer.cpp

HEADERS += \
    HolidayPackageManager.h \
    Holiday.h \
    HolidayPackage.h \
    HolidayPackageExtractor.h \
    HolidayOutputer.h

DISTFILES += \
    format.csv \
    packages/RU.csv \
    packages/GEEK \
    packages/INVALID
