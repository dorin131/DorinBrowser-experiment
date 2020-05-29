#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "value.h"

namespace js {

class Executable
{
public:
    virtual Value execute() = 0;
};

} // namespace js

#endif // EXECUTABLE_H
