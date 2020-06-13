#include "object_statement.h"

namespace js {

ObjectStatement::ObjectStatement()
{

}

Node* ObjectStatement::get(Identifier i)
{
    auto search = object_map.find(i);

    if (search != object_map.end()) {
        return search->second;
    }
    return new Literal(Token(Token::UNDEFINED, ""));
};

bool ObjectStatement::has(Identifier i)
{
    auto search = object_map.find(i);
    return search != object_map.end();
}

void ObjectStatement::set(Identifier ident, Node* expr)
{
    object_map.insert({ident, expr});
};

Value ObjectStatement::execute(Interpreter &)
{
    return Value(Value::OBJECT, "{}");
}

void ObjectStatement::dump(int indent)
{
    print_indent(indent);
    std::cout << "Object" << std::endl;
    // print object_map
}

} // namespace js