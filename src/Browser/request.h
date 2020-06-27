#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>
#include <sstream>
#include "../../libs/curlpp-0.8.1/include/curlpp/cURLpp.hpp"
#include "../../libs/curlpp-0.8.1/include/curlpp/Easy.hpp"
#include "../../libs/curlpp-0.8.1/include/curlpp/Options.hpp"

class Request
{
public:
    Request();

    static std::string get(std::string);
};

#endif // REQUEST_H
