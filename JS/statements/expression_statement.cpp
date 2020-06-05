#include "expression_statement.h"

namespace js {

ExpressionStatement::ExpressionStatement(Expression* exp): expression(exp)
{

}

void ExpressionStatement::dump(int indent)
{
    std::cout << indent << "ExpressionStatement";
};

Value ExpressionStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
