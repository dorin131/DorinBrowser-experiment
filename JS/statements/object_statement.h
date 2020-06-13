#ifndef OBJECTLITERALEXPRESSION_H
#define OBJECTLITERALEXPRESSION_H

#include "statement.h"
#include "../expressions/identifier.h"
#include "../expressions/literal.h"

namespace js {

class ObjectStatement : public Statement
{
public:
    ObjectStatement();

    Node* get(Identifier);
    bool has(Identifier);
    void set(Identifier, Node*);

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "Object"; };
private:
    std::map<Identifier, Node*> object_map;
    inline std::map<Identifier, Node*> get_map() { return object_map; };
};

} // namespace js

#endif // OBJECTLITERALEXPRESSION_H
