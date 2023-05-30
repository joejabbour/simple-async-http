#include "session.h"

static int sessioncnt = 0;

session::session(io_context &io_context):socket_(io_context)
    {
        sessioncnt++;
    }

void session::start()
    {
        
        
        async_read_until(socket_,buf,"\r\n\r\n",[this](const boost::system::error_code& error, std::size_t s)
        {
            if (!error)
            {
                
                
                http_request httprequest_ ;
                std::istream hstream(&buf);
                httprequest_.parseheader(hstream);  
                
                if (httprequest_.method == "GET")
                 {
                    std::cout << "get : " << httprequest_.url << std::endl;
                    http_response httpresponse_;
                    
                    
                    if (httprequest_.url == "/login.html")
                        {
                            httpresponse_.load_page_and_send(this,"login.html");
                        }
                    
                    else {
                        httpresponse_.load_page_and_send(this,"index.html");
                    }
                   
                    
                    

                   

                    
                 } 
                 else
                 {
                    std::cout << "not supported method \n";
                    delete this;
                 }            
                
            }
            else
            {
                std::cout << "error in read: " <<error <<std::endl;
                delete this;
            }
        }
        );
        
        
    }

tcp::socket& session::get_socket ()
    {
        return socket_;
    }

session::~session()
    {
        sessioncnt--;
        //it seems deleting the session object closes the socket
    }