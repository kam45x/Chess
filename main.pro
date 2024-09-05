TEMPLATE = app
TARGET = chess

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += src/game.h \
    src/clickable_label.h \
    src/chess_board.h

SOURCES += src/main.cpp \
    src/game.cpp \
    src/clickable_label.cpp \
    src/chess_board.cpp