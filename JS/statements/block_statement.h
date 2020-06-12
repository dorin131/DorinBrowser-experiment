#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <list>
#include <vector>

#include "statement.h"
#include "../expressions/object.h"

namespace js {

class BlockStatement : public Statement
{
public:
    BlockStatement();

    /**
     * @brief Add a SourceElement
     */
    void append(Statement*);
    inline std::list<Statement*> get_elements() { return source_elements; };

    void associate_arguments(std::vector<Node*>);
    void add_parameters(std::list<Identifier>);

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "BlockStatement"; };
private:
    /**
     * @brief A list of Statements
     */
    std::list<Statement*> source_elements;
    Object local_scope;
    std::list<Identifier> parameters;
};

} // namespace js

#endif // BLOCKSTATEMENT_H
