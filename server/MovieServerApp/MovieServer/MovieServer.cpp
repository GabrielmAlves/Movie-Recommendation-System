#include "httplib.h"
#include "include/config.h"
#include <iostream>

int main()
{
	httplib::Server server;

	server.Post(config::ROUTE_RECOMMEND, [](const httplib::Request& req, httplib::Response& res) {
		std::string input = req.body;
		std::cout << "Recebido: " << input << std::endl;
	});
	std::cout << "Servidor rodando em http://localhost:" << config::SERVER_PORT <<  std::endl;
	server.listen(config::SERVER_IP, config::SERVER_PORT);
	return 0;
}
