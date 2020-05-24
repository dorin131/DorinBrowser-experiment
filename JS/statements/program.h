#ifndef PROGRAM_H
#define PROGRAM_H

#include <list>

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
};

} // namespace js

#endif // PROGRAM_H
