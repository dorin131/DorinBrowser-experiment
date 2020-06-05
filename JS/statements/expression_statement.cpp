#include "expression_statement.h"

namespace js {

ExpressionStatement::ExpressionStatement(Expression* exp): expression(exp)
{

}

std::string ExpressionStatement::get_type()
{
    return "ExpressionStatement";
};

void ExpressionStatement::dump(int indent)
{
    std::cout << indent << "ExpressionStatement";
};

Value ExpressionStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
