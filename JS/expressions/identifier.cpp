#include "identifier.h"

namespace js {

Identifier::Identifier(Token token): token(token)
{

}

bool Identifier::operator<(const Identifier& rhs) const
{
    return token.get_value() < rhs.get_token().get_value();
};

void Identifier::dump(int indent)
{
    std::cout << indent << "Identifier";
};

Value Identifier::execute(Interpreter&)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
