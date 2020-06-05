#include "literal.h"

namespace js {

Literal::Literal(Token t)
    : token(t)
{

}

Value Literal::execute()
{
    switch(token.get_type()) {
    case(Token::STRING):
        return Value(Value::STRING, token.get_value());
    case(Token::NUMBER):
        return Value(Value::NUMBER, token.get_value());
    default:
        // TODO: Handle this better
        return Value(Value::STRING, "Unknown");
    }
}

void Literal::dump(int indent)
{
    std::cout << indent << "Literal: " << token.get_value();
}

std::string Literal::get_type()
{
    return "Literal";
}

} // namespace js
