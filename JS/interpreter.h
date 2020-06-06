#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <list>

#include "value.h"
#include "./statements/block_statement.h"

namespace js {

class Interpreter
{
public:
    Interpreter();

    Value run(BlockStatement*);
private:
    std::list<BlockStatement*> scope_stack;

    void enter_scope(BlockStatement*);
    void exit_scope();

    // Helpers
    bool is_top_level_block_statement(BlockStatement*);
    bool is_return_statement(Statement*);
};

} // namespace js

#endif // INTERPRETER_H
