#ifndef PARSER_H
#define PARSER_H

#include <functional>

#include "error.h"
#include "token.h"
#include "tokenizer.h"
#include "expressions/expression.h"
#include "expressions/identifier.h"
#include "expressions/binary_expression.h"
#include "expressions/literal.h"
#include "statements/program.h"
#include "statements/variable_statement.h"
#include "statements/if_statement.h"
#include "statements/return_statement.h"
#include "statements/function_declaration.h"
#include "statements/expression_statement.h"

/**
 * @brief The Parser class is defining the context-free grammar for our JS implementation
 * which is based on the ECMA Script grammar (https://www.ecma-international.org/ecma-262/10.0/index.html#sec-lexical-grammar).
 * We are going to use BNF (Backus-Naur form) to visually represent it.
 * This BNF context-free grammar is implemented using a FSM (Finite State Machine)
 */

namespace js {

class Parser
{
public:
    Parser(Tokenizer);

    Program* parse_program();
private:
    Tokenizer tokenizer;
    Token current_token;
    Token peek_token;

    enum Precedence
    {
        LOWEST,
        EQUALS,
        LESSGREATER,
        SUM,
        PRODUCT,
        PREFIX,
        CALL
    };

    std::map<Token::Type, Precedence> precedences = {
        {Token::EQ, Precedence::EQUALS},
        {Token::NE, Precedence::EQUALS},
        {Token::LT, Precedence::LESSGREATER},
        {Token::GT, Precedence::LESSGREATER},
        {Token::ADD, Precedence::SUM},
        {Token::SUB, Precedence::SUM},
        {Token::DIV, Precedence::PRODUCT},
        {Token::MUL, Precedence::PRODUCT},
        {Token::LPAREN, Precedence::CALL}
    };

    // Parsers
    Statement* parse_statement();
    VariableStatement* parse_variable_statement();
    IfStatement* parse_if_statement();
    ReturnStatement* parse_return_statement();
    FunctionDeclaration* parse_function_declaration();
    ExpressionStatement* parse_expression_statement();
    Node* parse_expression(Precedence);
    Literal* parse_literal_expression();
    Node* parse_grouped_expression();
    BinaryExpression* parse_binary_expression(Node*);
    Identifier* parse_identifier();
    BlockStatement* parse_block_statement();

    // Helpers
    void next_token();
    bool current_token_is(Token::Type);
    bool peek_token_is(Token::Type);
    Precedence peek_precedence();
    Precedence current_precedence();
};

} //namespace js

#endif // PARSER_H
