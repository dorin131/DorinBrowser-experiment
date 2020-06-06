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
        last_value = statement->execute(this);

        if (!is_top_level_block_statement(block_statement) && is_return_statement(statement)) {
            has_returned = true;
            break;
        }
    }

    exit_scope();

    if (!is_top_level_block_statement(block_statement) && !has_returned) {
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

}

bool Interpreter::is_top_level_block_statement(BlockStatement* block_statement)
{
    return block_statement->get_type() == "Program";
}

bool Interpreter::is_return_statement(Statement* node)
{
    return node->get_type() == "ReturnStatement";
}

} //namespace js
