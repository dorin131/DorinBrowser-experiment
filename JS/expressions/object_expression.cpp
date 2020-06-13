#include "object_expression.h"

namespace js {

ObjectExpression::ObjectExpression(Identifier name, std::list<Identifier> path)
    : name(name), path(path)
{

}

Value ObjectExpression::execute(Interpreter &)
{
    return Value(Value::OBJECT, "{}");
}

void ObjectExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "ObjectExpression" << std::endl;
}

} // namespace js
