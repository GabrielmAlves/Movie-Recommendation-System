#include "httplib.h"
#include "include/config.h"
#include "include/router.h"
#include "include/json.hpp"
#include <iostream>
using json = nlohmann::json;

int main()
{
	httplib::Server server;
	setup_routes(server);
	
	std::cout << "Servidor rodando em http://localhost:" << config::SERVER_PORT <<  std::endl;
	server.listen(config::SERVER_IP, config::SERVER_PORT);
	return 0;
}
