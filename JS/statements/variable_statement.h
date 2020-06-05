#ifndef VARIABLESTATEMENT_H
#define VARIABLESTATEMENT_H

#include "statement.h"
#include "../expressions/expression.h"
#include "../expressions/identifier.h"

namespace js {

class VariableStatement : public Statement
{
public:
    VariableStatement(Identifier ident, Expression* expr);

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
private:
    Identifier identifier;
    Expression* expression;
};
} // namespace js

#endif // VARIABLESTATEMENT_H
