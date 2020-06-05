#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <iostream>

#include "expression.h"

namespace js {

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::string op, Node* left, Node* right);

    // Overrides
    inline std::string get_type() override { return "BinaryExpression"; };
    Value execute() override;
    void dump(int indent) override;
private:
    std::string op;
    Node* left;
    Node* right;
};

} // namespace js

#endif // BINARYEXPRESSION_H
