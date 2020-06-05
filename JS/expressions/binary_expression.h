#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <iostream>

#include "expression.h"

namespace js {

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::string op, Node* left, Node* right);
    Value execute() override;
    std::string get_type() override;
    void dump(int indent) override;
private:
    std::string op;
    Node* left;
    Node* right;
};

} // namespace js

#endif // BINARYEXPRESSION_H
