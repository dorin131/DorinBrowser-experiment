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

std::string VariableStatement::get_type()
{
    return "VariableStatement";
}

Value VariableStatement::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
