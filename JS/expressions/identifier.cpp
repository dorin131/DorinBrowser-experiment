#include "identifier.h"
#include "../interpreter.h"

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

Value Identifier::execute(Interpreter& i)
{
    return i.get_global().get(*this)->execute(i);
};

} // namespace js
