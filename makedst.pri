#-------------------------------------------------
#
# Build Output Setting
#
#-------------------------------------------------

MOC_DIR =     _moc
OBJECTS_DIR = _obj
UI_DIR =      _ui
RCC_DIR=      _rcc

CONFIG(debug, debug|release) {
    QMAKE_CFLAGS_DEBUG   += -O0
    QMAKE_CXXFLAGS_DEBUG += -O0
}
