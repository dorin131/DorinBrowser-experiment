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
    print_indent(indent);
    std::cout << "Identifier" << std::endl;
    print_indent(indent + 1);
    std::cout << token.get_value() << std::endl;
};

Value Identifier::execute(Interpreter& i)
{
    return i.get_global()->get(*this)->execute(i);
};

} // namespace js
