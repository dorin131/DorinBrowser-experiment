include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    tst_parser.h \
    tst_tokenizer.h \
    ../JS/tokenizer.h \
    ../JS/token.h \
    ../JS/parser.h \
    ../JS/node.h \
    ../JS/statements/program.h \
    ../JS/statements/statement.h \
    ../JS/statements/expression_statement.h \
    ../JS/statements/function_declaration.h \
    ../JS/statements/if_statement.h \
    ../JS/statements/return_statement.h \
    ../JS/statements/variable_statement.h \
    ../JS/expressions/expression.h \
    ../JS/expressions/identifier.h \

SOURCES += \
        main.cpp \
        ../JS/tokenizer.cpp \
        ../JS/token.cpp \
        ../JS/parser.cpp \
        ../JS/node.cpp \
        ../JS/statements/program.cpp \
        ../JS/statements/statement.cpp \
        ../JS/statements/expression_statement.cpp \
        ../JS/statements/function_declaration.cpp \
        ../JS/statements/if_statement.cpp \
        ../JS/statements/return_statement.cpp \
        ../JS/statements/variable_statement.cpp \
        ../JS/expressions/expression.cpp \
        ../JS/expressions/identifier.cpp \
