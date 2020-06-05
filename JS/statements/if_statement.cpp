#include "if_statement.h"

namespace js {

IfStatement::IfStatement()
{

}

std::string IfStatement::get_type()
{
    return "IfStatement";
};

void IfStatement::dump(int indent)
{
    std::cout << indent << "IfStatement";
};

Value IfStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
