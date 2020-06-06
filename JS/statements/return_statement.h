#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "statement.h"

namespace js {

class ReturnStatement : public Statement
{
public:
    ReturnStatement();

    // Overrides
    Value execute(Interpreter*) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "ReturnStatement"; };
};

} // namespace js

#endif // RETURNSTATEMENT_H
