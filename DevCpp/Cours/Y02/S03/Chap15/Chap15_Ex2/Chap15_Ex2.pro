QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Chap10_Ex2
DEFINES += WIN64
HEADERS += ./chap10_ex2.h
SOURCES += ./chap10_ex2.cpp \
    ./main.cpp
FORMS += ./chap10_ex2.ui
