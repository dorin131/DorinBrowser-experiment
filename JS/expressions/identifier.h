#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "expression.h"
#include "../token.h"

namespace js {

class Identifier : public Expression
{
public:
    Identifier(Token token);

    inline Token get_token() const { return token; };

    // Overrides
    inline std::string get_type() override { return "Identifier"; };
    void dump(int indent) override;
    Value execute(Interpreter&) override;

    // Comparator because we want to use this class as map key
    bool operator<(const Identifier&) const;
private:
    Token token;
};

} // namespace js

#endif // IDENTIFIER_H
