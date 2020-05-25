#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "tokenizer.h"
#include "statements/program.h"

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

    // Parsers
    Statement parse_statement();
    //BlockStatement* parse_block_statement();
    //VariableStatement* parse_variable_statement();
    //...
};

} //namespace js

#endif // PARSER_H
