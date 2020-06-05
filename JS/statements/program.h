#ifndef PROGRAM_H
#define PROGRAM_H

#include <list>
#include <iostream>

#include "statement.h"

namespace js {

/**
 * @brief Is the topmost node in the AST
 */
class Program: public Statement
{
    /**
     * @brief A list of Statements
     */
    std::list<Statement*> source_elements;
public:
    Program();

    /**
     * @brief Add a SourceElement
     */
    void append(Statement*);
    inline std::list<Statement*> get_elements() { return source_elements; };

    // Overrides
    Value execute() override;
    void dump(int indent) override;
    inline std::string get_type() override { return "Program"; };
};

} // namespace js

#endif // PROGRAM_H
