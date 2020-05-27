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
    std::list<Statement> source_elements;
public:
    Program();

    /**
     * @brief Add a SourceElement
     */
    void append(Statement);

    std::string to_string()
    {
        std::string out = "Program";
        for (Statement s : source_elements) {
            out += "\n\t" + s.to_string();
        }
        return out + '\n';
    };
};

} // namespace js

#endif // PROGRAM_H
