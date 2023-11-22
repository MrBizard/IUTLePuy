QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = ModelView
DEFINES += WIN64 QT_DLL
HEADERS += ./ModelView.h
SOURCES += ./main.cpp \
    ./ModelView.cpp
FORMS += ./ModelView.ui
RESOURCES += ModelView.qrc
