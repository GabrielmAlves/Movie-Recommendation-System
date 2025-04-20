#include "httplib.h"
#include <iostream>

int main()
{
	httplib::Server server;

	server.Post("/recomendar", [](const httplib::Request& req, httplib::Response& res) {
		std::string input = req.body;
		std::cout << "Recebido: " << input << std::endl;
	});
	std::cout << "Servidor rodando em http://localhost:5000" << std::endl;
	server.listen("0.0.0.0", 5000);
	return 0;
}
