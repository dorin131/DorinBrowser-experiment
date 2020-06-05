#include "identifier.h"

namespace js {

Identifier::Identifier(Token token): token(token)
{

}

std::string Identifier::get_type()
{
    return "Identifier";
};

void Identifier::dump(int indent)
{
    std::cout << indent << "Identifier";
};

Value Identifier::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
