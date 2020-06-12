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

    Node* get(Identifier);
    void set(Identifier, Node*);

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "ObjectLiteralExpression"; };
private:
    std::map<Identifier, Node*> object_map;
    inline std::map<Identifier, Node*> get_map() { return object_map; };
};

} // namespace js

#endif // OBJECTLITERALEXPRESSION_H
