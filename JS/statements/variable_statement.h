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

    // Overrides
    Value execute() override;
    void dump(int indent) override;
    inline std::string get_type() override { return "VariableStatement"; };
private:
    Identifier identifier;
    Expression* expression;
};
} // namespace js

#endif // VARIABLESTATEMENT_H
