#include "../httplib.h"

class utils {
public:
	std::string GetToken(httplib::SSLClient sslClient) {
		auto tokenResponse = sslClient.Get("/token");
	}
};
