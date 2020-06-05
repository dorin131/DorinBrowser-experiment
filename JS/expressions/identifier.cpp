#include "identifier.h"

namespace js {

Identifier::Identifier(Token token): token(token)
{

}

void Identifier::dump(int indent)
{
    std::cout << indent << "Identifier";
};

Value Identifier::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
