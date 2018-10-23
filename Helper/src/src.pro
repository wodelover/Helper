QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += qml.qrc \
    font.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Face/release/ -lFace
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Face/debug/ -lFace
else:unix: LIBS += -L$$OUT_PWD/../Face/ -lFace
INCLUDEPATH += $$PWD/../Face
DEPENDPATH += $$PWD/../Face

#系统配置文件
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ProcessIni/release/ -lProcessIni
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ProcessIni/debug/ -lProcessIni
else:unix: LIBS += -L$$OUT_PWD/../ProcessIni/ -lProcessIni
INCLUDEPATH += $$PWD/../ProcessIni
DEPENDPATH += $$PWD/../ProcessIni

#系统日志
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Logger/release/ -lLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Logger/debug/ -lLogger
else:unix: LIBS += -L$$OUT_PWD/../Logger/ -lLogger
INCLUDEPATH += $$PWD/../Logger
DEPENDPATH += $$PWD/../Logger

#系统语言切换
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LanguageTranslator/release/ -lLanguageTranslator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LanguageTranslator/debug/ -lLanguageTranslator
else:unix: LIBS += -L$$OUT_PWD/../LanguageTranslator/ -lLanguageTranslator
INCLUDEPATH += $$PWD/../LanguageTranslator
DEPENDPATH += $$PWD/../LanguageTranslator

HEADERS += \
    initregister.h
