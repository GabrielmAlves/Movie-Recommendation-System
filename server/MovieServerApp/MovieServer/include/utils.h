#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../httplib.h"
#include "../../include/json.hpp"
#include <iostream>

class utils {
public:
	httplib::Result GetToken(httplib::Client& client) {
		auto tokenResponse = client.Get("/token");
		std::string static token;

		if (tokenResponse && tokenResponse->status == 200) {
			using json = nlohmann::json;
			auto tokenBody = json::parse(tokenResponse->body);
			token = tokenBody["token"];

			std::cout << "Token obtido: " << token << std::endl;
		} else {
			std::cout << "Erro ao obter o token!" << std::endl;
		}

		return tokenResponse;
	}
};
