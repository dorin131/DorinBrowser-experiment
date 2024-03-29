TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += interpreter.h \
    error.h \
    expressions/call_expression.h \
    expressions/object_expression.h \
    statements/object_statement.h \
    token.h \
    node.h \
    parser.h \
    tokenizer.h \
    value.h \
    expressions/binary_expression.h \
    expressions/expression.h \
    expressions/identifier.h \
    expressions/literal.h \
    statements/block_statement.h \
    statements/expression_statement.h \
    statements/function_declaration.h \
    statements/if_statement.h \
    statements/program.h \
    statements/return_statement.h \
    statements/statement.h \
    statements/variable_statement.h \

SOURCES += interpreter.cpp \
    error.cpp \
    expressions/call_expression.cpp \
    expressions/object_expression.cpp \
    statements/object_statement.cpp \
    token.cpp \
    main.cpp \
    node.cpp \
    parser.cpp \
    tokenizer.cpp \
    value.cpp \
    expressions/binary_expression.cpp \
    expressions/expression.cpp \
    expressions/identifier.cpp \
    expressions/literal.cpp \
    statements/block_statement.cpp \
    statements/expression_statement.cpp \
    statements/function_declaration.cpp \
    statements/if_statement.cpp \
    statements/program.cpp \
    statements/return_statement.cpp \
    statements/statement.cpp \
    statements/variable_statement.cpp \
