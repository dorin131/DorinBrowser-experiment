#include "call_expression.h"
#include "../interpreter.h"

namespace js {

CallExpression::CallExpression(Node* exp, std::vector<Node*> args)
    : expression(exp), arguments(args)
{

}

Value CallExpression::execute(Interpreter& i)
{
    Node* callee = expression;

    if (expression->get_type() == "Identifier") {
        callee = find_in_scope(i, static_cast<Identifier*>(callee));
    }

    if (callee->get_type() == "FunctionDeclaration") {
        auto function = static_cast<FunctionDeclaration*>(callee);
        function->get_body()->associate_arguments(arguments);
        return function->get_body()->execute(i);
    }

    return callee->execute(i);
}

Node* CallExpression::find_in_scope(Interpreter& inter, Identifier* ident)
{
    auto local_scopes = inter.get_local_scopes();
    for(Object* local_scope : local_scopes) {
        if(local_scope->has(*ident)) {
            return local_scope->get(*ident);
        }
    }
    return inter.get_global()->get(*ident);
}

void CallExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "CallExpression" << std::endl;
    expression->dump(indent + 1);
};

} // namespace js
