#include "../../include/router.h"
#include "../../include/config.h"
#include "../../include/reccomend.h"
#include "../../include/create_account.h"

void setup_routes(httplib::Server& server) {
	server.Post(config::ROUTE_RECOMMEND, handle_recommend);
	server.Post(config::ROUTE_SIGN_UP, handle_signup);
	server.Post(config::ROUTE_LOGIN, handle_login);
}