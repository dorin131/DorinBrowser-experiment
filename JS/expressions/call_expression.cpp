#include "call_expression.h"
#include "../interpreter.h"

namespace js {

CallExpression::CallExpression(Node* exp)
    : expression(exp)
{

}

Value CallExpression::execute(Interpreter& i)
{
    Node* callee = expression;

    if (expression->get_type() == "Identifier") {
        callee = i.get_global()->get(*static_cast<Identifier*>(callee));
    }

    if (callee->get_type() == "FunctionDeclaration") {
        return static_cast<FunctionDeclaration*>(callee)->get_body()->execute(i);
    }

    return callee->execute(i);
}

void CallExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "CallExpression" << std::endl;
    expression->dump(indent + 1);
};

} // namespace js
