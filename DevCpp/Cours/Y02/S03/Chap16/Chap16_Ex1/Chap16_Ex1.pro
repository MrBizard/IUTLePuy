QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Chap11_Ex1
DEFINES += WIN64 QT_DLL
HEADERS += ./chap11_ex1.h
SOURCES += ./chap11_ex1.cpp \
    ./main.cpp
FORMS += ./chap11_ex1.ui
RESOURCES += chap11_ex1.qrc
