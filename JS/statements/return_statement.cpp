#include "return_statement.h"

namespace js {

ReturnStatement::ReturnStatement()
{

}

std::string ReturnStatement::get_type()
{
    return "ReturnStatement";
};

void ReturnStatement::dump(int indent)
{
    std::cout << indent << "ReturnStatement";
};

Value ReturnStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
