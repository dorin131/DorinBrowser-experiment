#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "expression.h"
#include "../token.h"

namespace js {

class Identifier : public Expression
{
public:
    Identifier(Token token);
private:
    Token token;
};

} // namespace js

#endif // IDENTIFIER_H
