#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <list>

#include "value.h"
#include "./statements/object_statement.h"
#include "./statements/block_statement.h"

namespace js {

class Interpreter
{
public:
    Interpreter();

    Value run(BlockStatement*);

    inline ObjectStatement* get_global() { return &global_scope; };
    inline std::list<BlockStatement*> get_scope_stack() { return scope_stack; };

    Node* find_in_scope(Identifier*);
private:
    ObjectStatement global_scope;
    //std::list<ObjectStatement*> local_scopes;
    std::list<BlockStatement*> scope_stack;

    void enter_scope(BlockStatement*);
    void exit_scope();

    // Helpers
    bool is_top_level_block_statement(BlockStatement*);
    bool is_return_statement(Statement*);
};

} // namespace js

#endif // INTERPRETER_H
