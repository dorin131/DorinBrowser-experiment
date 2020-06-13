#include "function_declaration.h"
#include "../interpreter.h"

namespace js {

FunctionDeclaration::FunctionDeclaration(Identifier name, BlockStatement* body, std::list<Identifier> parameters)
    : name(name), body(body), parameters(parameters)
{
    body->add_parameters(parameters);
}

void FunctionDeclaration::dump(int indent)
{
    print_indent(indent);
    std::cout << "FunctionDeclaration" << std::endl;
    body->dump(indent + 1);
};

Value FunctionDeclaration::execute(Interpreter& i)
{
    // If function has name, put on global scope
    if (name.get_token().get_value().size() > 0) {
        i.get_global()->set(name, this);
    }
    return Value(Value::UNDEFINED, "");
};

} // namespace js
