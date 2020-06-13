#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H

#include "statement.h"
#include "../expressions/identifier.h"
#include "block_statement.h"

namespace js {

class FunctionDeclaration : public Statement
{
public:
    FunctionDeclaration(Identifier name, BlockStatement* body, std::list<Identifier> parameters);

    inline BlockStatement* get_body() { return body; };

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "FunctionDeclaration"; };
private:
    Identifier name;
    BlockStatement* body;
    std::list<Identifier> parameters;
};

} // namespace js

#endif // FUNCTIONDECLARATION_H
