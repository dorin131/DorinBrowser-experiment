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
    default:
        return parse_expression_statement();
    }
}

ExpressionStatement* Parser::parse_expression_statement()
{
    return new ExpressionStatement(parse_expression(Precedence::LOWEST));
}

Node* Parser::parse_expression(Precedence precedence)
{
    Node* left;

    switch(current_token.get_type()) {
    case(Token::NUMBER):
    case(Token::STRING):
        left = parse_literal_expression();
        break;
    case(Token::LPAREN):
        left = parse_grouped_expression();
        break;
    case(Token::IDENTIFIER):
        left = parse_identifier();
        break;
    case(Token::FUNCTION):
        left = parse_function_declaration();
        break;
    default:
        throw SyntaxError("Unexpected token when parsing expression: " + current_token.get_value());
    }

    while(!peek_token_is(Token::SEMICOLON) && !peek_token_is(Token::COMMA) && precedence < peek_precedence()) {
        next_token();
        switch(current_token.get_type()) {
        case(Token::LPAREN):
            left = parse_call_expression(left);
            break;
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

BinaryExpression* Parser::parse_binary_expression(Node* left)
{
    Token token = current_token;
    Precedence precedence = current_precedence();
    next_token();
    return new BinaryExpression(token.get_value(), left, parse_expression(precedence));
}

Node* Parser::parse_grouped_expression()
{
    next_token();
    auto expression = parse_expression(Precedence::LOWEST);

    if (!peek_token_is(Token::RPAREN)) {
        throw SyntaxError("Expected closing parenthesys");
    }
    next_token();
    return expression;
}

VariableStatement* Parser::parse_variable_statement()
{
    next_token();
    if (!current_token_is(Token::IDENTIFIER)) {
        throw SyntaxError("Expecting identifier after \"var\" statement");
    }
    Token identifier = current_token;
    next_token();

    if (!current_token_is(Token::ASSIGN)) {
        throw SyntaxError("Expected variable value assignment");
    }
    next_token();
    Node* expression = parse_expression(Precedence::LOWEST);

    return new VariableStatement(Identifier(identifier), expression);
}

FunctionDeclaration* Parser::parse_function_declaration()
{
    next_token();
    if (!current_token_is(Token::LPAREN)) {
        throw SyntaxError("Expected left paren after function declaration");
    }

    auto params = parse_function_parameters();

    if (!peek_token_is(Token::LBRACE)) {
        throw SyntaxError("Expected left brace");
    }
    next_token(); // LBRACE
    auto body = parse_block_statement();

    return new FunctionDeclaration(body, params);
}

std::list<Identifier> Parser::parse_function_parameters()
{
    std::list<Identifier> parameters;
    next_token();
    while (!current_token_is(Token::RPAREN)) {
        if (current_token_is(Token::IDENTIFIER)) {
            parameters.push_front(current_token);
            next_token();
        }
    }
    return parameters;
}

BlockStatement* Parser::parse_block_statement()
{
    next_token();
    auto block_statement = new BlockStatement();

    while (!current_token_is(Token::RBRACE)) {
        block_statement->append(parse_statement());
        next_token();
    }

    return block_statement;
}

Identifier* Parser::parse_identifier()
{
    return new Identifier(current_token);
}

ReturnStatement* Parser::parse_return_statement()
{
    next_token();

    auto return_statement =  new ReturnStatement(parse_expression(Precedence::LOWEST));

    if (peek_token_is(Token::SEMICOLON)) {
        next_token();
    }

    return return_statement;
}

CallExpression* Parser::parse_call_expression(Node * node)
{
    auto call_expression = new CallExpression(node);

    while (!current_token_is(Token::RPAREN)) {
        next_token();
    }

    return call_expression;
}

IfStatement* Parser::parse_if_statement()
{
    return new IfStatement();
}

} // namespace js
