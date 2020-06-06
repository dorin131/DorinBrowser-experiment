#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <list>

#include "value.h"

namespace js {

class Interpreter
{
public:
    Interpreter();

    Value run();
private:
    void enter_scope();
    void exit_scope();
};

} // namespace js

#endif // INTERPRETER_H
