#include "http_response.h"

   void http_response::prepare_get(std::ostream &os) //content must be populated
    {
        
        os << version << " " << status << "\r\n";
        os <<"Content-Type: " << content_type << "\r\n";
        os <<"Content-Length: " << content.size() << "\r\n";
        os <<"\r\n";
        
    }

    void http_response::load_page_and_send(session *sesh,std::string path)
    {
         version = "http/1.1";
         status = "200 OK";
         content_type = "text/html";
         // buf.consume(buf.size());
         std::ostream ostr(&sesh->buf);
         std::ifstream page(path);
         if(!page.is_open())
         {

          content = "<h1>server: could not load page</h1>";
          content_length = content.size(); 
          prepare_get(ostr); 
          ostr<<content;
          ostr << "<h1>server: could not load page</h1>";
          std::cout << "could not open file\n";
          
         }
         else 
         {

         std::stringstream bufstream;
         bufstream << page.rdbuf();
         content = bufstream.str();
         content_length = content.size();
         prepare_get(ostr);  
         ostr<<content;             
         }

         sesh->get_socket().async_write_some(sesh->buf.data(),[sesh](const boost::system::error_code &error,std::size_t size)
                    {
                        if (!error)
                        {
                                                       
                        }
                        else{
                            std::cout <<"error in write";
                        }
                        delete sesh;
                    }
                    );
    }