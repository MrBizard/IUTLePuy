QT += core
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Chap9_Ex1
DEFINES += WIN64
HEADERS += ./qcontroleur.h \
    ./qvase.h
SOURCES += ./main.cpp \
    ./qcontroleur.cpp \
    ./qvase.cpp
