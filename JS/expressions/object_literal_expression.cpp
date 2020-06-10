#include "object_literal_expression.h"

namespace js {

ObjectLiteralExpression::ObjectLiteralExpression()
{

}

Expression* ObjectLiteralExpression::get(Identifier i)
{
    auto search = object_map.find(i);

    if (search != object_map.end()) {
        return search->second;
    }
    return new Literal(Token(Token::UNDEFINED, ""));
};

void ObjectLiteralExpression::set(Identifier ident, Expression* expr)
{
    object_map.insert({ident, expr});
};

Value ObjectLiteralExpression::execute(Interpreter &)
{
    return Value(Value::UNDEFINED, "");
}

void ObjectLiteralExpression::dump(int indent)
{
    print_indent(indent);
    std::cout << "ObjectLiteralExpression\n";
    // print object_map
}

} // namespace js
