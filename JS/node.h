#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "value.h"

namespace js {

class Node
{
public:
    Node();
    virtual ~Node();

    virtual std::string get_type() = 0;
    virtual void dump(int indent) = 0;
    virtual Value execute() = 0;
};

} // namespace js

#endif // NODE_H
