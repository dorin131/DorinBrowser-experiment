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
    std::list<Statement*> get_elements();

    Value execute() override;
    void dump(int indent) override;
    std::string get_type() override;
};

} // namespace js

#endif // PROGRAM_H
