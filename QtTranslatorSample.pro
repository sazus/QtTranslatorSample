TEMPLATE = subdirs
CONFIG  += orderd

SUBDIRS += \
    # 起動前に言語設定
    $$PWD/01_StaticTranslation \
    # 動的に言語設定(だけど正常動作しない)
    $$PWD/02_DynamicTranslationNG \
    # 動的に言語設定(正常動作版)
    $$PWD/03_DynamicTranslation
