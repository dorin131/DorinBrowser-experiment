#ifndef LITERAL_H
#define LITERAL_H

#include "expression.h"
#include "../token.h"

namespace js {

class Literal : public Expression
{
public:
    Literal(Token);
private:
    Token token;
};

} // namespace js

#endif // LITERAL_H
