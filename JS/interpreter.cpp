#include "interpreter.h"

namespace js {

Interpreter::Interpreter()
{

}

Value Interpreter::run(BlockStatement* block_statement)
{
    bool has_returned = false;
    Value last_value = Value(Value::UNDEFINED, "");

    enter_scope(block_statement);
    for (Statement* statement : block_statement->get_elements()) {
        last_value = statement->execute(*this);

        if (!is_top_level_block_statement(block_statement) && is_return_statement(statement)) {
            has_returned = true;
            break;
        }
    }

    auto top_level = is_top_level_block_statement(block_statement);

    exit_scope();

    if (!top_level && !has_returned) {
        return Value(Value::UNDEFINED, "");
    }

    return last_value;
}

void Interpreter::enter_scope(BlockStatement* block_statement)
{
    scope_stack.push_front(block_statement);
}

void Interpreter::exit_scope()
{
    //delete scope_stack.front();
    scope_stack.pop_front();
}

bool Interpreter::is_top_level_block_statement(BlockStatement* block_statement)
{
    return block_statement->get_type() == "Program";
}

bool Interpreter::is_return_statement(Statement* node)
{
    return node->get_type() == "ReturnStatement";
}

Node* Interpreter::find_in_scope(Identifier* ident)
{
    for(BlockStatement* block : scope_stack) {
        if(block->get_local_scope()->has(*ident)) {
            return block->get_local_scope()->get(*ident);
        }
    }
    return get_global()->get(*ident);
}

} //namespace js
