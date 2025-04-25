#include "../../include/create_account.h"
#include "../../include/json.hpp"
#include "../../include/user.h"
#include <iostream>
#include <memory>
#include <vector>

using json = nlohmann::json;

void handle_signup(const httplib::Request& req, httplib::Response& res) {

	try {
		auto requestBodyJson = json::parse(req.body);
		std::string userName = requestBodyJson["name"];
		std::string userAppName = requestBodyJson["username"];
		std::string userEmail = requestBodyJson["email"];
		std::string userPassword = requestBodyJson["password"];
		
		if (requestBodyJson.contains("genres") && requestBodyJson["genres"].is_array()) {
			std::vector<std::string> genres = requestBodyJson["genres"].get<std::vector<std::string>>();
		}
		std::shared_ptr<User> user = std::make_shared<User>(userName, userAppName, userEmail, userPassword);
		
		CreateAccount createAccount;
		createAccount.CreateUserAccount(*user);

		json responseJson;
		responseJson["message"] = "Conta criada com sucesso!";
		res.set_content(responseJson.dump(), "application/json");
		res.status = 200;
	}
	catch (const std::exception& e) {
		std::cerr << "Erro ao processar JSON: " << e.what() << "\n";
		res.status = 400;
		res.set_content("JSON inválido", "text/plain");
	}

}

void CreateAccount::CreateUserAccount(User& user) {
	std::cout << user.userAge << std::endl;
}