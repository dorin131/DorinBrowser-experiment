#include "node.h"

namespace js {

Node::Node()
{

}

std::string Node::to_string()
{
    return "Node";
};

Value Node::execute()
{
    return Value(Value::UNDEFINED, "");
}

} // namespace js
