#include "program.h"

namespace js {

Program::Program()
{

}

void Program::append(Statement* source_element)
{
    source_elements.push_front(source_element);
}

void Program::dump(int indent)
{
    std::cout << "Program\n";
    for (Statement* s : this->source_elements) {
        s->dump(indent + 1);
    }
};

Value Program::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
