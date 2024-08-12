TEMPLATE = app
TARGET = chess

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += src/game.h
SOURCES +=  src/main.cpp src/game.cpp