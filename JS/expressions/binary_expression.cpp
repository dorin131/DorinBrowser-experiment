#include "binary_expression.h"

namespace js {

BinaryExpression::BinaryExpression(std::string op, Node* left, Node* right)
    : op(op), left(left), right(right)
{

}

Value BinaryExpression::execute(Interpreter* i)
{
    Value l = left->execute(i);
    Value r = right->execute(i);

    return Value(Value::NUMBER, std::to_string(std::stoi(l.get_value()) + std::stoi(r.get_value())));
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
