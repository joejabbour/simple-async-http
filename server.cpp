    #include "server.h"
    
    server::server(io_context &io_context):acceptor_(io_context,tcp::endpoint(tcp::v4(), 8082))
    {
        session_ptr =new session (io_context);
        acceptor_.async_accept(session_ptr->get_socket(),[this,&io_context](const boost::system::error_code& error)
            {
                server::handle_accept(error,io_context/*,this->session_ptr*/);
            }
            );
    }

    void server::handle_accept(const boost::system::error_code& error, io_context &io_context/*, session *session_ptr*/)
        {
            if(!error)
            {
                session_ptr->start();
                
                session_ptr=new session (io_context);
                
                acceptor_.async_accept(session_ptr->get_socket(),[this,&io_context](const boost::system::error_code& error)
                    {
                      server::handle_accept(error,io_context);
                    }
                   );

            }
            else
            {           
                std::cout << "error\n";
                delete session_ptr; //double check this
            }
        }

    server::~server()
    {
        std::cout << "server closed\n";
    }