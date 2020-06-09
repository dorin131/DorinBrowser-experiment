#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <list>

#include "statement.h"

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

    // Overrides
    Value execute(Interpreter&) override;
    void dump(int indent) override;
    inline std::string get_type() override { return "BlockStatement"; };
private:
    /**
     * @brief A list of Statements
     */
    std::list<Statement*> source_elements;
};

} // namespace js

#endif // BLOCKSTATEMENT_H
