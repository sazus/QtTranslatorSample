QT     += qml quick
include($$PWD/../makedst.pri)

CONFIG += c++11

TEMPLATE = app
TARGET =   TranslationTest

HEADERS += \
    $$PWD/src/uicontrol.h

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/uicontrol.cpp

RESOURCES += \
    $$PWD/qml/qml.qrc

TRANSLATIONS +=\
    $$PWD/i18n/$${TARGET}_en_US.ts \
    $$PWD/i18n/$${TARGET}_ja_JP.ts \
    $$PWD/i18n/$${TARGET}_zh_CN.ts

translation_only {
    SOURCES += \
        $$PWD/qml/main.qml
}

RESOURCES += \
    $$PWD/i18n/i18n.qrc

