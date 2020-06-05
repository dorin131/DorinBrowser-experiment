#include "statement.h"

namespace js {

Statement::Statement()
{

}

void Statement::dump(int indent)
{
    std::cout << indent << "statement test";
}

std::string Statement::get_type()
{
    return "Statement";
}

Value Statement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
