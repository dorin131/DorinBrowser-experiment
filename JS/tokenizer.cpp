#include "tokenizer.h"

namespace js {

Tokenizer::Tokenizer(std::string code)
{
    this->code = code;
    read_char();
}

char Tokenizer::peek_char()
{
    if (read_position >= (int) code.length()) {
        return 0;
    }
    return code[read_position];
}

void Tokenizer::read_char()
{
    if (read_position >= (int) code.length()) {
        ch = 0;
    } else {
        ch = code[read_position];
    }
    position = read_position;
    read_position++;
}

Token Tokenizer::next_token()
{
    Token* t;

    if (position == int(code.length())) {
        return *new Token(Token::EOS, 0);
    }

    skip_whitespace();

    switch (ch) {
    case '=':
        if (peek_char() == '=') {
            read_char();
            t = new Token(Token::EQ, "==");
        } else {
            t = new Token(Token::ASSIGN, ch);
        }
        break;
    case '<':
        if (peek_char() == '=') {
            read_char();
            t = new Token(Token::LTE, "<=");
        } else {
            t = new Token(Token::LT, ch);
        }
        break;
    case '>':
        if (peek_char() == '=') {
            read_char();
            t = new Token(Token::GTE, ">=");
        } else {
            t = new Token(Token::GT, ch);
        }
        break;
    case '!':
        if (peek_char() == '=') {
            read_char();
            t = new Token(Token::NE, "!=");
        } else {
            t = new Token(Token::NOT, ch);
        }
        break;
    case ':':
        t = new Token(Token::COLON, ch);
        break;
    case ';':
        t = new Token(Token::SEMICOLON, ch);
        break;
    case '(':
        t = new Token(Token::LPAREN, ch);
        break;
    case ')':
        t = new Token(Token::RPAREN, ch);
        break;
    case ',':
        t = new Token(Token::COMMA, ch);
        break;
    case '+':
        t = new Token(Token::ADD, ch);
        break;
    case '-':
        t = new Token(Token::SUB, ch);
        break;
    case '*':
        t = new Token(Token::SUB, ch);
        break;
    case '/':
        t = new Token(Token::DIV, ch);
        break;
    case '{':
        t = new Token(Token::LBRACE, ch);
        break;
    case '}':
        t = new Token(Token::RBRACE, ch);
        break;
    case '.':
        t = new Token(Token::PERIOD, ch);
        break;
    case '\"':
        t = new Token(Token::STRING, read_until(ch));
        break;
    case '\'':
        t = new Token(Token::STRING, read_until(ch));
        break;
    case 0:
        t = new Token(Token::EOS, ch);
        break;
    default:
        if (is_letter()) {
            std::string value = read_identifier();
            Token::Type type = get_identifier_type(value);
            return *new Token(type, value);
        } else if (is_digit()) {
            return *new Token(Token::NUMBER, read_number());
        }
        t = new Token(Token::ILLEGAL, ch);
    }

    read_char();
    return *t;
}

bool Tokenizer::is_digit()
{
    return ch >= '0' && ch <= '9';
}

bool Tokenizer::is_single_quote()
{
    return ch == '\'';
}

bool Tokenizer::is_double_quote()
{
    return ch == '\"';
}

void Tokenizer::skip_whitespace()
{
    while (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
        read_char();
    }
}

bool Tokenizer::is_letter()
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

std::string Tokenizer::read_identifier()
{
    int start_pos = position;
    while (is_letter() || is_digit()) {
        read_char();
    }
    return code.substr(start_pos, position - start_pos);
}

std::string Tokenizer::read_until(char end_char)
{
    read_char();
    int start_pos = position;
    while (ch != end_char) {
        read_char();
    }
    return code.substr(start_pos, position - start_pos);
}

std::string Tokenizer::read_number()
{
    int start_pos = position;
    while (is_digit()) {
        read_char();
    }
    return code.substr(start_pos, position - start_pos);
}

Token::Type Tokenizer::get_identifier_type(std::string value)
{
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);

    if (Token::keywords.find(value) != Token::keywords.end()) {
        return Token::keywords.at(value);
    }
    return Token::IDENTIFIER;
}

} // namespace js
