#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "value.h"

namespace js {

class Node
{
public:
    Node();

    std::string to_string();
    Value execute();
};

} // namespace js

#endif // NODE_H
