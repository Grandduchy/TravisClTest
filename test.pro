TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#Use c++14
QMAKE_CXXFLAGS += -std=c++11
#Use Version 5 of g++
QMAKE_CXX = g++−4.9
QMAKE_LINK = g++−4.9
QMAKE_CC = gcc-4.9


SOURCES += \
        main.cpp
