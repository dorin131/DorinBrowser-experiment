#include "return_statement.h"

namespace js {

ReturnStatement::ReturnStatement()
{

}

void ReturnStatement::dump(int indent)
{
    std::cout << indent << "ReturnStatement";
};

Value ReturnStatement::execute(Interpreter*)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
