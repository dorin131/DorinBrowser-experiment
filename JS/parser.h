#ifndef PARSER_H
#define PARSER_H

#include <functional>

#include "token.h"
#include "tokenizer.h"
#include "expressions/expression.h"
#include "expressions/identifier.h"
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

    Program parse_program();
private:
    Tokenizer tokenizer;
    Token current_token;
    Token peek_token;

    void next_token();
    bool current_token_is(Token::Type);
    bool peek_token_is(Token::Type);

    typedef std::function<Node(Parser&)> parse_prefix_function;
    typedef std::function<Node(Expression)> parse_infix_function;

    // Parsers
    Statement parse_statement();
    VariableStatement parse_variable_statement();
    IfStatement parse_if_statement();
    ReturnStatement parse_return_statement();
    FunctionDeclaration parse_function_declaration();
    ExpressionStatement parse_expression_statement();
    Expression parse_expression();

//    const std::map<Token::Type, parse_prefix_function> parse_prefix_functions {
//        {Token::IDENTIFIER, &Parser::parse_statement}
//    };

//    const std::map<Token::Type, parse_infix_function> parse_infix_functions {
//        {Token::ADD, 0}
//    };
};

} //namespace js

#endif // PARSER_H
