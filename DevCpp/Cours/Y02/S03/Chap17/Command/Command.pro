QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = Command
DEFINES += WIN64 QT_DLL
HEADERS += ./QUndoCommandUser.h \
    ./command.h
SOURCES += ./command.cpp \
    ./main.cpp \
    ./QUndoCommandUser.cpp
FORMS += ./command.ui
RESOURCES += command.qrc
