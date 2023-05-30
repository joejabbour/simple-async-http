#include <boost/asio.hpp>
#include "server.h"


int main()
{
    io_context io_context_;
    server s(io_context_);
    io_context_.run();

}