#include "variable_statement.h"

namespace js {

VariableStatement::VariableStatement(Identifier ident, Expression expr)
    : identifier(ident), expression(expr)
{

}

} // namespace js
