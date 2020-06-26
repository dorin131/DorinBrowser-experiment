#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

class Request
{
public:
    Request();

    static std::string get(std::string);
};

#endif // REQUEST_H
