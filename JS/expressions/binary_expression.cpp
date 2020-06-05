#include "binary_expression.h"

namespace js {

BinaryExpression::BinaryExpression(std::string op, Node* left, Node* right)
    : op(op), left(left), right(right)
{

}

Value BinaryExpression::execute()
{
//    Value l = left.execute();
//    Value r = right.execute();

//    return Value(Value::NUMBER, std::to_string(std::stoi(l.get_value()) + std::stoi(r.get_value())));
    return Value(Value::NUMBER, "5");
}

void BinaryExpression::dump(int indent)
{
    std::cout << indent << "BinaryExpression";
};

} // namespace js
