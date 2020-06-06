#include "function_declaration.h"

namespace js {

FunctionDeclaration::FunctionDeclaration()
{

}

void FunctionDeclaration::dump(int indent)
{
    std::cout << indent << "FunctionDeclaration";
};

Value FunctionDeclaration::execute(Interpreter*)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
