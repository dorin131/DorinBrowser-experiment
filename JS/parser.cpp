#include "parser.h"

namespace js {

Parser::Parser(Tokenizer t)
    : tokenizer(t)
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

Parser::Precedence Parser::current_precedence()
{
    if (precedences.find(current_token.get_type()) != precedences.end()) {
        return precedences.at(current_token.get_type());
    }
    return Precedence::LOWEST;
}

Parser::Precedence Parser::peek_precedence()
{
    if (precedences.find(peek_token.get_type()) != precedences.end()) {
        return precedences.at(peek_token.get_type());
    }
    return Precedence::LOWEST;
}

Program* Parser::parse_program()
{
    Program* program = new Program();
    while (!current_token_is(Token::EOS)) {
        program->append(parse_statement());
        next_token();
    }
    return program;
}

Statement* Parser::parse_statement()
{
    switch(current_token.get_type()) {
    case(Token::VAR):
        return parse_variable_statement();
    case(Token::IF):
        return parse_if_statement();
    case(Token::RETURN):
        return parse_return_statement();
    case(Token::FUNCTION):
        return parse_function_declaration();
    default:
        return parse_expression_statement();
    }
}

ExpressionStatement* Parser::parse_expression_statement()
{
    return new ExpressionStatement(parse_expression(Precedence::LOWEST));
}

Expression* Parser::parse_expression(Precedence precedence)
{
    Expression* left;

    switch(current_token.get_type()) {
    case(Token::NUMBER):
    case(Token::STRING):
        left = parse_literal_expression();
        break;
    default:
        break;
    }

    while(!peek_token_is(Token::SEMICOLON) && !peek_token_is(Token::COMMA) && precedence < peek_precedence()) {
        next_token();
        switch(current_token.get_type()) {
        case(Token::LPAREN):
            //left = parse_call_expression(left);
            //break;
        default:
            left = parse_binary_expression(left);
        }
    }

    if (peek_token_is(Token::SEMICOLON)) {
        next_token();
    }

    return left;
}

Literal* Parser::parse_literal_expression()
{
    return new Literal(current_token);
}

BinaryExpression* Parser::parse_binary_expression(Expression* left)
{
    Token token = current_token;
    Precedence precedence = current_precedence();
    next_token();
    return new BinaryExpression(token.get_value(), left, parse_expression(precedence));
}

VariableStatement* Parser::parse_variable_statement()
{
    next_token();
    if (!current_token_is(Token::IDENTIFIER)) {

    }
    Token identifier = current_token;
    next_token();

    if (!current_token_is(Token::ASSIGN)) {

    }
    next_token();
    Expression* expression = parse_expression(Precedence::LOWEST);

    while (!current_token_is(Token::SEMICOLON)) {
        next_token();
    }
    return new VariableStatement(Identifier(identifier), expression);
}

IfStatement* Parser::parse_if_statement()
{
    return new IfStatement();
}

ReturnStatement* Parser::parse_return_statement()
{
    return new ReturnStatement();
}

FunctionDeclaration* Parser::parse_function_declaration()
{
    return new FunctionDeclaration();
}

} // namespace js
