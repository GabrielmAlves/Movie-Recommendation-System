#define CPPHTTLIB_OPENSSL_SUPPORT
#include "../../include/config.h"
#include "../../include/login.h"
#include "../../include/utils.h"
#include "../../include/json.hpp"
#include <iostream>
#include <memory>

using json = nlohmann::json;

void handle_login(const httplib::Request req, const httplib::Response res) {
	try {
		auto loginBody = json::parse(req.body);
		std::cout << "Login JSON bruto:\n" << loginBody.dump(4) << std::endl;
		std::string username = loginBody["username"];
		std::string password = loginBody["password"];

		std::cout << username << std::endl;
		std::cout << password << std::endl;
		
		std::shared_ptr<Login> login = std::make_shared<Login>(username, password);

		login->UserLogin(login, username, password);
	}
	catch (const std::exception& e) {
		std::cout << "Erro ao processar os dados: " << e.what() << std::endl;
	}
}

void Login::UserLogin(const std::shared_ptr<Login>& loginObject, const std::string username, std::string password) {

	httplib::Client tokenClient("localhost", 6000);
	httplib::SSLClient sslClient(config::FIREBASE_CLIENT, 443);
	std::string static token;

	auto tokenResponse = tokenClient.Get("/token");

	if (tokenResponse && tokenResponse->status == 200) {
		auto token_json = nlohmann::json::parse(tokenResponse->body);
		token = token_json["access_token"];
		std::cout << "Token: " << token << std::endl;
	}
	else {
		std::cout << "ERRO!!" << std::endl;
	}

	httplib::Headers headers = {
		{"Content-Type", "application/json"},
		{"Authorization", "Bearer " + token}
	};

	json bodyJson = {
		{ "structuredQuery", {
			{ "from", { { { "collectionId", "usuarios" } } } },
			{ "where", {
				{ "fieldFilter", {
					{ "field", { { "fieldPath", "nome" } } },
					{ "op", "EQUAL" },
					{ "value", { { "stringValue", username } } }
				} }
			} },
			{ "limit", 1 }
		} }
	};

	std::string body = bodyJson.dump();

	auto response = sslClient.Post(config::FIREBASE_QUERY_NO_ID, headers, body, "application/json");

	if (!response) {
		std::cerr << "Erro de conexão: " << response.error() << std::endl;
	}

	if (response->status != 200) {
		std::cerr << "Erro HTTP: " << response->status << "\n" << response->body << std::endl;
	}

	json responseJson = json::parse(response->body);

	if (responseJson.empty() && !responseJson[0].contains("document")) {
		std::cout << "Usuario n\306o encontrado!" << std::endl;
	}

	std::string passwordStored = responseJson[0]["document"]["fields"]["senha"]["stringValue"];

	if (passwordStored == password) {
		std::cout << "Senha correta.\n";
	}
	else {
		std::cout << "Senha incorreta.\n";
	}

}