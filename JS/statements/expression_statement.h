#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include "statement.h"
#include "../expressions/expression.h"

namespace js {

class ExpressionStatement : public Statement
{
public:
    ExpressionStatement(Expression);
private:
    Expression expression;
};

} //namespace js

#endif // EXPRESSIONSTATEMENT_H
