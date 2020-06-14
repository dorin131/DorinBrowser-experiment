#include "object_expression.h"

namespace js {

ObjectExpression::ObjectExpression(Identifier name, std::list<Identifier> path)
    : name(name), path(path)
{

}

Value ObjectExpression::execute(Interpreter & i)
{
    ObjectStatement* obj = static_cast<ObjectStatement*>(i.find_in_scope(&name));
    Node* expr = obj;
    for(Identifier id : path) {
        expr = static_cast<ObjectStatement*>(expr)->get(id);
    }
    return expr->execute(i);
}

void ObjectExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "ObjectExpression" << std::endl;
    print_indent(indent + 1);
    std::cout << name.get_token().get_value();
    for(Identifier i : path) {
        std::cout << "." << i.get_token().get_value();
    }
    std::cout << std::endl;
}

} // namespace js
