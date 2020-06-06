#include "program.h"

namespace js {

Program::Program()
{

}

void Program::dump(int indent)
{
    std::cout << "Program" << std::endl;
    for (Statement* s : get_elements()) {
        s->dump(indent + 1);
    }
};

Value Program::execute(Interpreter*)
{
    return Value(Value::UNDEFINED, "");
};

} // namespace js
