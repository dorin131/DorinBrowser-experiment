#include "binary_expression.h"

namespace js {

BinaryExpression::BinaryExpression(std::string op, Node left, Node right)
    : op(op), left(left), right(right)
{

}

} // namespace js
