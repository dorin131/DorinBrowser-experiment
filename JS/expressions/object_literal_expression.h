#ifndef OBJECTLITERALEXPRESSION_H
#define OBJECTLITERALEXPRESSION_H

#include "expression.h"
#include "identifier.h"
#include "literal.h"

namespace js {

class ObjectLiteralExpression : public Expression
{
public:
    ObjectLiteralExpression();

    Expression* get(Identifier);
    void set(Identifier, Expression*);

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "ObjectLiteralExpression"; };
private:
    std::map<Identifier, Expression*> object_map;
};

} // namespace js

#endif // OBJECTLITERALEXPRESSION_H
