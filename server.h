#ifndef server_h
#define server_h

#include <iostream>
#include <boost/asio.hpp>
#include "session.h"

using namespace boost::asio;
using ip::tcp;

class session;

class server
{
    private:
    tcp::acceptor acceptor_;
    session *session_ptr;

    public:
   
    server(io_context &io_context);


    void handle_accept(const boost::system::error_code& error, io_context &io_context/*, session *session_ptr*/);
  

    ~server();
    
};

#endif