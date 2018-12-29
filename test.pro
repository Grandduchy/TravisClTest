TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#Use c++14
QMAKE_CXXFLAGS += -std=c++14
#Use Version 5 of g++
QMAKE_CXX = g++−5
QMAKE_LINK = g++−5
QMAKE_CC = g++-5


SOURCES += \
        main.cpp
