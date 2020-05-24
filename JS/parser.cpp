#include "parser.h"

namespace js {

Parser::Parser(Tokenizer* tokenizer)
{
    this->tokenizer = tokenizer;
}

void Parser::next_token()
{
    current_token = peek_token;
    peek_token = tokenizer->next_token();
}

void Parser::parse_program()
{
    while (!current_token_is(Token::EOS)) {
        // TODO: Parse
    }
}

bool Parser::current_token_is(Token::Type type)
{
    return current_token->get_type() == type;
}

} // namespace js
