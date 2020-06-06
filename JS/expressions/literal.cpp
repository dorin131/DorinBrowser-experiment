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
    print_intent(indent);
    std::cout << "Literal\n";
    print_intent(indent + 1);
    std::cout << token.get_value() << std::endl;
}

} // namespace js
