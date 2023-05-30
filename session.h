#ifndef session_h
#define session_h

#include <boost/asio.hpp>
#include <iostream>
#include "http_request.h"
#include "http_response.h"

using namespace boost::asio;
using ip::tcp;

class session
{
    
    int sessionnb;

    private:

    tcp::socket socket_;
    http_request packet;
    
    

    public:

    boost::asio::streambuf buf;
   
    session(io_context &);
   
    void start();

    tcp::socket& get_socket ();
   
    ~session();
    
};

#endif