#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../../include/create_account.h"
#include "../../include/json.hpp"
#include "../../include/user.h"
#include "../../include/config.h"
#include <iostream>
#include <memory>
#include <vector>

using json = nlohmann::json;

void handle_signup(const httplib::Request& req, httplib::Response& res) {

	std::vector<std::string>* genres = new std::vector<std::string>;

	try {
		auto requestBodyJson = json::parse(req.body);
		std::string userName = requestBodyJson["name"].get<std::string>();
		std::string userAppName = requestBodyJson["username"].get<std::string>();
		std::string userEmail = requestBodyJson["email"].get<std::string>();
		std::string userPassword = requestBodyJson["password"].get<std::string>();
		
		if (requestBodyJson.contains("genres") && requestBodyJson["genres"].is_array()) {
			*genres = requestBodyJson["genres"].get<std::vector<std::string>>();
		}
		std::shared_ptr<User> user = std::make_shared<User>(userName, userAppName, userEmail, userPassword, genres);
		std::cout << user->getUserName() << std::endl;
		std::cout << user->getUserAppName() << std::endl;
		std::cout << user->getUserEmail() << std::endl;
		
		for (const auto& g : *genres) {
			std::cout << g << std::endl;
		}
		CreateAccount createAccount;
		createAccount.CreateUserAccount(*user);

		json responseJson;
		responseJson["message"] = config::ACCOUNT_CREATED;
		res.set_content(responseJson.dump(), "application/json");
		res.status = 200;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao processar JSON: " << e.what() << "\n";
		res.status = 400;
		res.set_content("JSON inválido", "text/plain");
	}
	delete genres;
}

void CreateAccount::CreateUserAccount(User& user) {
	std::string url = "/v1/projects/" + config::PROJECT_ID +
		"/databases/(default)/documents/" + config::COLLECTION;
	
	httplib::Client tokenClient("localhost", 6000);
	httplib::SSLClient sslClient(config::FIREBASE_CLIENT, 443);
	sslClient.enable_server_certificate_verification(false);
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
	{ "Content-Type", "application/json" },
	{ "Authorization", "Bearer " + token }
	};

	json firestoreData;
	json genreArray = json::array();

	firestoreData["fields"]["nome"]["stringValue"] = user.getUserName();
	firestoreData["fields"]["email"]["stringValue"] = user.getUserEmail();
	firestoreData["fields"]["idade"]["integerValue"] = 23;  
	firestoreData["fields"]["senha"]["stringValue"] = user.getUserPassword();

	for (const auto& genre : *user.userMovieGenrePreferences) {
		genreArray.emplace_back(json{{"stringValue", genre} });
	}
	firestoreData["fields"]["preferidos"]["arrayValue"]["values"] = genreArray;

	std::string body = firestoreData.dump();

	auto response = sslClient.Post(url, headers, body, "application/json");

	if (response && response->status == 200) {
		std::cout << "Sucesso: " << response->body << std::endl;
	}
	else {
		if (response) {
			std::cerr << "Erro: Código " << response->status << " - " << response->body << std::endl;
		}
		else {
			std::cerr << "Erro de conexão: " << response.error() << std::endl;
		}
	}
}