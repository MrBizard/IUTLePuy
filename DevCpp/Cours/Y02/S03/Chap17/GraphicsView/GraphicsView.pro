QT += core gui widgets
CONFIG += c++17
TEMPLATE = app
build_pass:CONFIG(debug, debug|release) {
      DESTDIR = ../Debug
  }
build_pass:CONFIG(release, debug|release) {
      DESTDIR = ../Release
  }

TARGET = GraphicsView
DEFINES += WIN64 QT_DLL
HEADERS += ./QUndoCommandCreate.h \
    ./qmagraphicsscene.h \
    ./qgraphicsviewwholescene.h \
    ./mainwindow.h
SOURCES += ./main.cpp \
    ./mainwindow.cpp \
    ./qgraphicsviewwholescene.cpp \
    ./qmagraphicsscene.cpp \
    ./QUndoCommandCreate.cpp
FORMS += ./mainwindow.ui
RESOURCES += mainwindow.qrc
