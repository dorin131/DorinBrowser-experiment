#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "statement.h"
#include "../expressions/expression.h"

namespace js {

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Node*);

    inline Node* get_expression() { return expression; };

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "ExpressionStatement"; };
private:
    Node* expression;
};

} //namespace js

#endif // EXPRESSIONSTATEMENT_H
