#include "../../include/reccomend.h"
#include <iostream>
#include "../../include/json.hpp"

using json = nlohmann::json;

void handle_recommend(const httplib::Request& req, httplib::Response res) {
	try {
		auto bodyJson = json::parse(req.body);
		std::string user = bodyJson["user"];
		std::string userEmail = bodyJson["email"];

		std::cout << "User: " << user << std::endl;
		std::cout << "User e-mail: " << userEmail << std::endl;

		res.set_content("Requisi\207\306o recebida com sucesso!", "text/plain");
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao processar JSON: " << e.what() << "\n";
		res.status = 400;
		res.set_content("JSON inválido", "text/plain");
	}

	std::string input = req.body;
	std::cout << "Recebido: " << input << std::endl;
}