#include "function_declaration.h"

namespace js {

FunctionDeclaration::FunctionDeclaration()
{

}

std::string FunctionDeclaration::get_type()
{
    return "FunctionDeclaration";
};

void FunctionDeclaration::dump(int indent)
{
    std::cout << indent << "FunctionDeclaration";
};

Value FunctionDeclaration::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
