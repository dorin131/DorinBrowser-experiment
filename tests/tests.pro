include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    tst_tokenizer.h \
    ../JS/tokenizer.h \
    ../JS/token.h \

SOURCES += \
        main.cpp \
        ../JS/tokenizer.cpp \
        ../JS/token.cpp \
