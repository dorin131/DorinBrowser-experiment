#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <iostream>

#include "../error.h"
#include "expression.h"

namespace js {

class BinaryExpression : public Expression
{
public:
    BinaryExpression(std::string op, Node* left, Node* right);

    inline Node* get_left() { return left; };
    inline Node* get_right() { return right; };
    inline std::string get_op() { return op; };

    // Overrides
    inline std::string get_type() override { return "BinaryExpression"; };
    Value execute(Interpreter*) override;
    void dump(int indent) override;
private:
    std::string op;
    Node* left;
    Node* right;

    Value string_arithmetic(Value, Value);
    Value number_arithmetic(Value, Value);
};

} // namespace js

#endif // BINARYEXPRESSION_H
