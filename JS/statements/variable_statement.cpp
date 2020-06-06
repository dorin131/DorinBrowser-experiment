#include "variable_statement.h"

namespace js {

VariableStatement::VariableStatement(Identifier ident, Expression* expr)
    : identifier(ident), expression(expr)
{

}

void VariableStatement::dump(int indent)
{
    std::cout << indent << "VariableStatement";
}

Value VariableStatement::execute(Interpreter*)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
