#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "expression.h"

namespace js {

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::string op, Node left, Node right);
private:
    std::string op;
    Node left;
    Node right;
};

} // namespace js

#endif // BINARYEXPRESSION_H
