#include "program.h"

namespace js {

Program::Program()
{

}

void Program::append(Statement* source_element)
{
    this->source_elements.push_front(source_element);
}

} // namespace js
