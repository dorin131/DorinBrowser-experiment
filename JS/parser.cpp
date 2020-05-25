#include "parser.h"
#include "statements/program.h"

namespace js {

Parser::Parser(Tokenizer tokenizer):
    tokenizer(tokenizer),
    current_token(tokenizer.next_token()),
    peek_token(tokenizer.next_token())
{

}

void Parser::next_token()
{
    current_token = peek_token;
    peek_token = tokenizer.next_token();
}

Program Parser::parse_program()
{
    Program program = Program();
    while (!current_token_is(Token::EOS)) {
        program.append(parse_statement());
    }
    return program;
}

Statement Parser::parse_statement()
{
    return Statement();
}

bool Parser::current_token_is(Token::Type type)
{
    return current_token.get_type() == type;
}

} // namespace js
