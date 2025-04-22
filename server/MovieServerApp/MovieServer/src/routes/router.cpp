#include "../../include/router.h"
#include "../../include/config.h"
#include "../../include/reccomend.h"

void setup_routes(httplib::Server& server) {
	server.Post(config::ROUTE_RECOMMEND, handle_recommend);
}