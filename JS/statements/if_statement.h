#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "statement.h"

namespace js {

class IfStatement : public Statement
{
public:
    IfStatement();

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
};

} // namespace js

#endif // IFSTATEMENT_H
