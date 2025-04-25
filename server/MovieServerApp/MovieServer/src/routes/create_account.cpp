#include "../../include/create_account.h"
#include "../../include/json.hpp"
#include "../../include/user.h"
#include <iostream>
#include <memory>

using json = nlohmann::json;

void handle_signup(const httplib::Request& req, httplib::Response& res) {

	try {
		auto requestBodyJson = json::parse(req.body);
		std::string userName = requestBodyJson["name"];
		std::string userAppName = requestBodyJson["username"];
		std::string userEmail = requestBodyJson["email"];
		std::string userPassword = requestBodyJson["password"];
		
		std::shared_ptr<User> user = std::make_shared<User>(userName, userAppName, userEmail, userPassword);
		CreateAccount createAccount;
		createAccount.CreateUserAccount(*user);
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