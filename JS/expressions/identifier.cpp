#include "identifier.h"
#include "../interpreter.h"

namespace js {

Identifier::Identifier(Token token): token(token)
{

}

Identifier::Identifier()
{
    // defaults to UNDEFINED token
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
    return find_in_scope(i, this)->execute(i);
};

Node* Identifier::find_in_scope(Interpreter& inter, Identifier* ident)
{
    auto local_scopes = inter.get_local_scopes();
    for(Object* local_scope : local_scopes) {
        if(local_scope->has(*ident)) {
            return local_scope->get(*ident);
        }
    }
    return inter.get_global()->get(*ident);
}

} // namespace js
