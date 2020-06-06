#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "expression.h"
#include "../token.h"

namespace js {

class Identifier : public Expression
{
public:
    Identifier(Token token);

    // Overrides
    inline std::string get_type() override { return "Identifier"; };
    void dump(int indent) override;
    Value execute(Interpreter*) override;
private:
    Token token;
};

} // namespace js

#endif // IDENTIFIER_H
