httpserver: http_request.cpp http_response.cpp server.cpp session.cpp serverapp.cpp 
	g++ -o httpserver http_request.cpp http_response.cpp server.cpp session.cpp serverapp.cpp -I.