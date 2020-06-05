#include "expression.h"

namespace js {

Expression::Expression()
{

}

void Expression::dump(int indent)
{
    std::cout << indent << "Expression";
};

} // namespace js
