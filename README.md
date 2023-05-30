# simple-async-http
This is a simple asynchronous http server built using Boost/Asio, the server asynchronously accepts and asynchronously reads http request. 
socket created in session constructor then async_accept called on the socket, async_accept called again in the callback for accept to handle new connections.
session-start() will async read the request and write html file accordingly
