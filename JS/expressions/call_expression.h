#ifndef CALLEXPRESSION_H
#define CALLEXPRESSION_H

#include "expression.h"
#include "identifier.h"
#include "../statements/function_declaration.h"

namespace js {

class CallExpression : public Expression
{
public:
    CallExpression(Node*, std::vector<Node*>);

    // Overrides
    inline std::string get_type() override { return "CallExpression"; };
    Value execute(Interpreter&) override;
    void dump(int indent) override;
private:
    Node* expression;
    std::vector<Node*> arguments;
};

} // namespace js

#endif // CALLEXPRESSION_H
