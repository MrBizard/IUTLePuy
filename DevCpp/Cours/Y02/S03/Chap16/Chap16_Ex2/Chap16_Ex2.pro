QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Chap11_Ex2
DEFINES += WIN64 QT_DLL
HEADERS += ./chap11_ex2.h \
    ./qcadredessin.h
SOURCES += ./chap11_ex2.cpp \
    ./main.cpp \
    ./qcadredessin.cpp
FORMS += ./chap11_ex2.ui
RESOURCES += chap11_ex2.qrc
