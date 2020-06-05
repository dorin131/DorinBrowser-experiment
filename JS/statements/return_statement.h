#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "statement.h"

namespace js {

class ReturnStatement : public Statement
{
public:
    ReturnStatement();

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
};

} // namespace js

#endif // RETURNSTATEMENT_H
