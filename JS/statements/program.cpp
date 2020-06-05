#include "program.h"

namespace js {

Program::Program()
{

}

void Program::append(Statement* source_element)
{
    this->source_elements.push_front(source_element);
}

std::list<Statement*> Program::get_elements()
{
    return this->source_elements;
}

std::string Program::get_type()
{
    return "Program";
}

void Program::dump(int indent)
{
    std::cout << indent << "Program";
    for (Statement* s : this->source_elements) {
        s->dump(indent + 2);
    }
};

Value Program::execute()
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
