#ifndef http_request_h
#define http_request_h

#include <iostream>
#include <string>
#include <sstream>
#include <map>


class http_request
{
    public:

    std::map<std::string, std::string> headers;
    std::string method;
    std::string url;
    std::string version;
   
    void parseheader(std::istream &);
 

};

#endif