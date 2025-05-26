#pragma once
#include <string>

namespace config {
	const int SERVER_PORT = 5000;
	const std::string SERVER_IP = "0.0.0.0";

	const std::string SERVER_ERROR_MSG = "Erro interno do servidor.";
	const std::string SERVER_SUCCESS_MSG = "Servidor em funcionamento.";
	const std::string ACCOUNT_CREATED = "Conta criada com sucesso!";
	
	const std::string ROUTE_LOGIN = "/login";
	const std::string ROUTE_SIGN_UP = "/signup";
	const std::string ROUTE_CHANGE_PASSWORD = "/change";
	const std::string ROUTE_RECOMMEND = "/recommend";

	const std::string PYTHON_AGENT_ENDPOINT = "";

	const std::string PROJECT_ID = "movie-recommendation-sys-caa01";
	const std::string COLLECTION = "usuarios";

	const std::string FIREBASE_CLIENT = "firestore.googleapis.com";
	const std::string FIREBASE_QUERY_NO_ID = "https://firestore.googleapis.com/v1/projects/movie-recommendation-sys-caa01/databases/(default)/documents:runQuery";
}