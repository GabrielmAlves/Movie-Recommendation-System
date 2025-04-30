#define CPPHTTLIB_OPENSSL_SUPPORT
#include "../../include/config.h"
#include "../../include/login.h"
#include "../../include/json.hpp"
#include <iostream>
#include <memory>

using json = nlohmann::json;

void handle_login(const httplib::Request req, const httplib::Response res) {
	try {
		auto loginBody = json::parse(req.body);
		std::string username = loginBody["username"];
		std::string password = loginBody["password"];
		
		std::shared_ptr<Login> login = std::make_shared<Login>(username, password);

		login->UserLogin(login);
	}
	catch (const std::exception& e) {
		std::cout << "Erro ao processar os dados: " << e.what() << std::endl;
	}
}

void Login::UserLogin(const std::shared_ptr<Login>& loginObject) {

}