#ifndef LITERAL_H
#define LITERAL_H

#include "expression.h"
#include "../token.h"

namespace js {

class Literal : public Expression
{
public:
    Literal(Token);

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
private:
    Token token;
};

} // namespace js

#endif // LITERAL_H
