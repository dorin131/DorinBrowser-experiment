#include "block_statement.h"

namespace js {

BlockStatement::BlockStatement()
{

}

void BlockStatement::append(Statement* source_element)
{
    source_elements.push_front(source_element);
}

} // namespace js
