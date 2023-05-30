   #include "http_request.h"
   
   void http_request::parseheader(std::istream &i)
    {
                std::string ignore,line,key,value;
              
                //get first line:
                std::getline(i,line,'\r');
                std::getline(i,ignore,'\n');
                //parse first line
                std::stringstream ss{line};
                
                ss >> method >> url >> version ;
                //parse remaining to map
        

                while (line.length()!=0)
                {
                
                std::getline(i,line,'\r');
                std::getline(i,ignore,'\n');
                ss.clear();
                ss.str(line);
                getline(ss,key,':');
                getline(ss,value);
                headers[key]=value;
                //std::cout << key<<":"<<value<<std::endl;
                }

            
    }