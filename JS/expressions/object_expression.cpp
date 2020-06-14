#include "object_expression.h"

namespace js {

ObjectExpression::ObjectExpression(Identifier name, std::list<Identifier> path)
    : name(name), path(path)
{

}

Value ObjectExpression::execute(Interpreter &)
{
    // TODO: find name in scope then drill in with path
    return Value(Value::OBJECT, "{}");
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
