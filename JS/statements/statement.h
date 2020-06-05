#ifndef STATEMENT_H
#define STATEMENT_H

#include "../node.h"

namespace js {

class Statement: public Node
{
public:
    Statement();

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
};

} // namespace js

#endif // STATEMENT_H
