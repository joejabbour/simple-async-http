#ifndef http_response_h
#define http_response_h

#include <iostream>
#include <fstream>
#include "session.h"

class session;

class http_response
{
    public:

    std::string version;
    std::string status;
    std::string content_type;
    std::string content_length;
    std::string content;   
    std::string response;
    std::string path;


    void prepare_get(std::ostream &); //content must be populated   
    void load_page_and_send(session *,std::string);
  

};

#endif