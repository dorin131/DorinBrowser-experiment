include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    tst_interpreter.h \
    tst_parser.h \
    tst_tokenizer.h \
    ../src/JS/error.h \
    ../src/JS/tokenizer.h \
    ../src/JS/token.h \
    ../src/JS/parser.h \
    ../src/JS/node.h \
    ../src/JS/value.h \
    ../src/JS/interpreter.h \
    ../src/JS/statements/program.h \
    ../src/JS/statements/statement.h \
    ../src/JS/statements/expression_statement.h \
    ../src/JS/statements/block_statement.h \
    ../src/JS/statements/function_declaration.h \
    ../src/JS/statements/if_statement.h \
    ../src/JS/statements/return_statement.h \
    ../src/JS/statements/variable_statement.h \
    ../src/JS/expressions/expression.h \
    ../src/JS/expressions/identifier.h \
    ../src/JS/expressions/literal.h \
    ../src/JS/expressions/binary_expression.h \
    ../src/JS/expressions/binary_expression.h \
    ../src/JS/statements/object_statement.h \
    ../src/JS/expressions/object_expression.h \

SOURCES += \
        main.cpp \
        ../src/JS/error.cpp \
        ../src/JS/tokenizer.cpp \
        ../src/JS/token.cpp \
        ../src/JS/parser.cpp \
        ../src/JS/node.cpp \
        ../src/JS/value.cpp \
        ../src/JS/interpreter.cpp \
        ../src/JS/statements/program.cpp \
        ../src/JS/statements/statement.cpp \
        ../src/JS/statements/expression_statement.cpp \
        ../src/JS/statements/block_statement.cpp \
        ../src/JS/statements/function_declaration.cpp \
        ../src/JS/statements/if_statement.cpp \
        ../src/JS/statements/return_statement.cpp \
        ../src/JS/statements/variable_statement.cpp \
        ../src/JS/expressions/expression.cpp \
        ../src/JS/expressions/identifier.cpp \
        ../src/JS/expressions/literal.cpp \
        ../src/JS/expressions/binary_expression.cpp \
        ../src/JS/expressions/call_expression.cpp \
        ../src/JS/statements/object_statement.cpp \
        ../src/JS/expressions/object_expression.cpp \
