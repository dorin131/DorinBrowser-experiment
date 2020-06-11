#include "variable_statement.h"
#include "../interpreter.h"

namespace js {

VariableStatement::VariableStatement(Identifier ident, Expression* expr)
    : identifier(ident), expression(expr)
{

}

void VariableStatement::dump(int indent)
{
    std::cout << indent << "VariableStatement";
}

Value VariableStatement::execute(Interpreter& i)
{
    i.get_global().set(identifier, expression);
    return Value(Value::UNDEFINED, "");
};

} // namespace js
