#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include "statement.h"

namespace js {

class FunctionDeclaration : public Statement
{
public:
    FunctionDeclaration();

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
};

} // namespace js

#endif // FUNCTIONDECLARATION_H
