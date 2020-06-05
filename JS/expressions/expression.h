#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../node.h"

namespace js {

class Expression: public Node
{
public:
    Expression();

    std::string get_type() override;
    void dump(int indent) override;
};

} // namespace js

#endif // EXPRESSION_H
