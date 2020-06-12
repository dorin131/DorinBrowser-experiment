#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include "statement.h"
#include "block_statement.h"

namespace js {

class FunctionDeclaration : public Statement
{
public:
    FunctionDeclaration(BlockStatement* body);

    inline BlockStatement* get_body() { return body; };

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "FunctionDeclaration"; };
private:
    BlockStatement* body;
};

} // namespace js

#endif // FUNCTIONDECLARATION_H
