#include "expression_statement.h"

namespace js {

ExpressionStatement::ExpressionStatement(Expression* exp): expression(exp)
{

}

void ExpressionStatement::dump(int indent)
{
    print_intent(indent);
    std::cout << "ExpressionStatement\n";
    expression->dump(indent + 1);
};

Value ExpressionStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
