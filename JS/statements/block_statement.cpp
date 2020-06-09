#include "block_statement.h"
#include "../interpreter.h"

namespace js {

BlockStatement::BlockStatement()
{

}

void BlockStatement::append(Statement* source_element)
{
    source_elements.push_front(source_element);
}

Value BlockStatement::execute(Interpreter& i)
{
    return i.run(this);
};

void BlockStatement::dump(int indent)
{
    print_indent(indent);
    std::cout << "BlockStatement" << std::endl;
};

} // namespace js
