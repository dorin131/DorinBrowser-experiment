#include "parser.h"

namespace js {

Parser::Parser(Tokenizer tokenizer)
    : tokenizer(tokenizer)
    , current_token(tokenizer.next_token())
    , peek_token(tokenizer.next_token())
{

}

void Parser::next_token()
{
    current_token = peek_token;
    peek_token = tokenizer.next_token();
}

bool Parser::current_token_is(Token::Type type)
{
    return current_token.get_type() == type;
}

bool Parser::peek_token_is(Token::Type type)
{
    return peek_token.get_type() == type;
}

Program Parser::parse_program()
{
    Program program = Program();
    while (!current_token_is(Token::EOS)) {
        program.append(parse_statement());
        next_token();
    }
    return program;
}

Statement Parser::parse_statement()
{
    if (current_token_is(Token::VAR)) {
        return parse_variable_statement();
    } else if (current_token_is(Token::IF)) {
        return parse_if_statement();
    } else if (current_token_is(Token::RETURN)) {
        return parse_return_statement();
    } else if (current_token_is(Token::FUNCTION)) {
        return parse_function_declaration();
    }
    return parse_expression_statement();
}

VariableStatement Parser::parse_variable_statement()
{
    next_token();
    if (!current_token_is(Token::IDENTIFIER)) {

    }
    Token identifier = current_token;
    next_token();

    if (!current_token_is(Token::ASSIGN)) {

    }
    next_token();
    Expression expression = parse_expression();

    while (!current_token_is(Token::SEMICOLON)) {
        next_token();
    }
    return VariableStatement(Identifier(identifier), expression);
}

IfStatement Parser::parse_if_statement()
{
    return IfStatement();
}

ReturnStatement Parser::parse_return_statement()
{
    return ReturnStatement();
}

FunctionDeclaration Parser::parse_function_declaration()
{
    return FunctionDeclaration();
}

ExpressionStatement Parser::parse_expression_statement()
{
    return ExpressionStatement();
}

Expression Parser::parse_expression()
{
    return Expression();
}

} // namespace js
