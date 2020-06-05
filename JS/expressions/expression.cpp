#include "expression.h"

namespace js {

Expression::Expression()
{

}

std::string Expression::get_type()
{
    return "Expression";
};

void Expression::dump(int indent)
{
    std::cout << indent << "Expression";
};

} // namespace js
