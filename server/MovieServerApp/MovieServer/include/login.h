#pragma once
#include "../httplib.h"
#include <string>

class Login {
private:
	const std::string _userName;
	std::string _userPassword;
public:
	void handle_login(const httplib::Request req, const httplib::Response res);
	void UserLogin(std::string userName, std::string userPassword);

	const std::string GetUsername() const { return _userName; }
};