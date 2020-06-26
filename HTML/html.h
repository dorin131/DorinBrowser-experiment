#ifndef HTML_H
#define HTML_H

#include <iostream>

namespace html {

class HTML
{
public:
    HTML();

    std::string parse(std::string); // should return an AST
};

} // namespace html

#endif // HTML_H
