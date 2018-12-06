#-------------------------------------------------
#
# Project created by QtCreator 2018-10-22T20:36:11
#
#-------------------------------------------------

QT       += gui

TARGET = Face
TEMPLATE = lib

DEFINES += FACE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#include(faceheader.pri)

SOURCES += \
        face.cpp \
    AirFaceOperater.cpp \
    FormatConversion.cpp

HEADERS += \
        face.h \
        face_global.h \  
    AirFaceOperater.h \
    FormatConversion.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

#opencv config
#INCLUDEPATH +=-L $$PWD/../Face/inc/opencv/include \
#                 $$PWD/../Face/inc/opencv/include/opencv \
#                 $$PWD/../Face/inc/opencv/include/opencv2
INCLUDEPATH +=-L $$PWD/inc/opencv/include \
                 $$PWD/inc/opencv/include/opencv \
                 $$PWD/inc/opencv/include/opencv2

LIBS += $$PWD/lib/opencv/libopencv_*.dll.a

#AirFace CONFIG
INCLUDEPATH += -L $$PWD/../Face/inc/airface

LIBS += $$PWD/lib/airface/libarcsoft_face_engine.lib

