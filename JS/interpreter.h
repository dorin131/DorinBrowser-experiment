#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <list>

#include "value.h"
#include "./expressions/object.h"
#include "./statements/block_statement.h"

namespace js {

class Interpreter
{
public:
    Interpreter();

    Value run(BlockStatement*);

    inline Object* get_global() { return &global_scope; };
    inline std::vector<Object> get_local_scopes() { return local_scopes; };
private:
    Object global_scope;
    std::vector<Object> local_scopes;
    std::list<BlockStatement*> scope_stack;

    void enter_scope(BlockStatement*);
    void exit_scope();

    // Helpers
    bool is_top_level_block_statement(BlockStatement*);
    bool is_return_statement(Statement*);
};

} // namespace js

#endif // INTERPRETER_H
