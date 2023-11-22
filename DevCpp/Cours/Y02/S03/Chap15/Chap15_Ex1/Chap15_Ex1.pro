QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Chap10_Ex1
DEFINES += WIN64
HEADERS += ./qkey.h
SOURCES += ./main.cpp \
    ./qkey.cpp
