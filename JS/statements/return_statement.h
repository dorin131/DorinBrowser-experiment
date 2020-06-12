#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "statement.h"

namespace js {

class ReturnStatement : public Statement
{
public:
    ReturnStatement(Node* expression);

    inline Node* get_expression() { return expression; };
    inline void set_expression(Node* n) { expression = n; };

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "ReturnStatement"; };
private:
    Node* expression;
};

} // namespace js

#endif // RETURNSTATEMENT_H
