#include "binary_expression.h"

namespace js {

BinaryExpression::BinaryExpression(std::string op, Node* left, Node* right)
    : op(op), left(left), right(right)
{

}

Value BinaryExpression::execute(Interpreter*)
{
//    Value l = left.execute();
//    Value r = right.execute();

//    return Value(Value::NUMBER, std::to_string(std::stoi(l.get_value()) + std::stoi(r.get_value())));
    return Value(Value::NUMBER, "5");
}

void BinaryExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "BinaryExpression" << std::endl;
    print_indent(indent + 1);
    std::cout << op << std::endl;
    left->dump(indent + 2);
    right->dump(indent + 2);
};

} // namespace js
