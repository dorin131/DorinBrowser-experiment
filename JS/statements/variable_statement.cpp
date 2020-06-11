#include "variable_statement.h"
#include "../interpreter.h"

namespace js {

VariableStatement::VariableStatement(Identifier ident, Expression* expr)
    : identifier(ident), expression(expr)
{

}

void VariableStatement::dump(int indent)
{
    print_indent(indent);
    std::cout << "VariableStatement" << std::endl;
    identifier.dump(indent + 1);
}

Value VariableStatement::execute(Interpreter& i)
{
    i.get_global().set(identifier, expression);
    return Value(Value::UNDEFINED, "");
};

} // namespace js
