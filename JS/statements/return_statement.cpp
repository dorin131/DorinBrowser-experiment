#include "return_statement.h"

namespace js {

ReturnStatement::ReturnStatement(Node* exp)
    : expression(exp)
{

}

void ReturnStatement::dump(int indent)
{
    print_indent(indent);
    std::cout << "ReturnStatement" << std::endl;
};

Value ReturnStatement::execute(Interpreter& i)
{
    return expression->execute(i);
};

} // namespace js
