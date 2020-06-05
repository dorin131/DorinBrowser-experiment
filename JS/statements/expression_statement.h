#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "statement.h"
#include "../expressions/expression.h"

namespace js {

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression*);

    inline Expression* get_expression() { return expression; };

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
private:
    Expression* expression;
};

} //namespace js

#endif // EXPRESSIONSTATEMENT_H
