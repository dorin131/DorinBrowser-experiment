HEADERS += token.h\
    expressions/binary_expression.h \
    expressions/expression.h \
    expressions/identifier.h \
    expressions/literal.h \
    interpreter.h \
    node.h \
    parser.h \
    statements/block_statement.h \
    statements/expression_statement.h \
    statements/function_declaration.h \
    statements/if_statement.h \
    statements/program.h \
    statements/return_statement.h \
    statements/statement.h \
    statements/variable_statement.h \
    tokenizer.h \
    value.h

SOURCES +=\
    expressions/binary_expression.cpp \
    expressions/expression.cpp \
    expressions/identifier.cpp \
    expressions/literal.cpp \
    interpreter.cpp \
    main.cpp \
    node.cpp \
    parser.cpp \
    statements/block_statement.cpp \
    statements/expression_statement.cpp \
    statements/function_declaration.cpp \
    statements/if_statement.cpp \
    statements/program.cpp \
    statements/return_statement.cpp \
    statements/statement.cpp \
    statements/variable_statement.cpp \
    token.cpp \
    tokenizer.cpp \
    value.cpp
