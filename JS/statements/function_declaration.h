#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include "statement.h"

namespace js {

class FunctionDeclaration : public Statement
{
public:
    FunctionDeclaration();

    // Overrides
    Value execute(Interpreter*) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "FunctionDeclaration"; };
};

} // namespace js

#endif // FUNCTIONDECLARATION_H
