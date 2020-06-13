#include "helpers.h"

namespace js {

Helpers::Helpers()
{

}

Node* Helpers::find_in_scope(Interpreter& inter, Identifier* ident)
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
