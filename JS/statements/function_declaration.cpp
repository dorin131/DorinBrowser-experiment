#include "function_declaration.h"

namespace js {

FunctionDeclaration::FunctionDeclaration(BlockStatement* body, std::list<Identifier> parameters)
    : body(body), parameters(parameters)
{

}

void FunctionDeclaration::dump(int indent)
{
    print_indent(indent);
    std::cout << "FunctionDeclaration" << std::endl;
    body->dump(indent + 1);
};

Value FunctionDeclaration::execute(Interpreter&)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
