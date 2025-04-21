#pragma once
#include <string>

namespace config {
	const int SERVER_PORT = 5000;
	const std::string SERVER_IP = "0.0.0.0";

	const std::string SERVER_ERROR_MSG = "Erro interno do servidor.";
	const std::string SERVER_SUCCESS_MSG = "Servidor em funcionamento.";
	
	const std::string ROUTE_LOGIN = "/login";
	const std::string ROUTE_SIGN_UP = "/signup";
	const std::string ROUTE_CHANGE_PASSWORD = "/change";
	const std::string ROUTE_RECOMMEND = "/recommend";

	const std::string PYTHON_AGENT_ENDPOINT = "";
}