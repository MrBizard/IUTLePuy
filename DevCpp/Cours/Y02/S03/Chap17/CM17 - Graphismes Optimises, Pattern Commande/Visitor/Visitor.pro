QT += core
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Visitor
CONFIG += console
DEFINES += WIN64
HEADERS += ./data.h \
    ./serializationclasses.h \
    ./serializationinterfaces.h
SOURCES += ./main.cpp \
    ./serialisationclasses.cpp
