#include "object.h"

namespace js {

Object::Object()
{

}

Node* Object::get(Identifier i)
{
    auto search = object_map.find(i);

    if (search != object_map.end()) {
        return search->second;
    }
    return new Literal(Token(Token::UNDEFINED, ""));
};

bool Object::has(Identifier i)
{
    auto search = object_map.find(i);
    return search != object_map.end();
}

void Object::set(Identifier ident, Node* expr)
{
    object_map.insert({ident, expr});
};

Value Object::execute(Interpreter &)
{
    return Value(Value::UNDEFINED, "");
}

void Object::dump(int indent)
{
    print_indent(indent);
    std::cout << "ObjectLiteralExpression\n";
    // print object_map
}

} // namespace js
