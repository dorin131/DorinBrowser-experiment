#include "request.h"

Request::Request()
{

}

std::string Request::get(std::string)
{
    try
    {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::options::Url>("https://fodor.org");

        std::ostringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        myRequest.perform();

        return os.str();
    }

    catch(curlpp::RuntimeError & e)
    {
        std::cout << e.what() << std::endl;
    }

    catch(curlpp::LogicError & e)
    {
        std::cout << e.what() << std::endl;
    }

    return "";
}
