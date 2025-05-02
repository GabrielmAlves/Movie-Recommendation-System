#pragma once
#include "../httplib.h"
#include <string>

void handle_login(const httplib::Request req, const httplib::Response res);

class Login {
private:
	const std::string _userName;
	std::string _userPassword;
public:
	void UserLogin(const std::shared_ptr<Login>& loginObject, const std::string username, std::string password);

	Login(const std::string username, std::string password) 
		: _userName(username), _userPassword(password) {}

	const std::string GetUsername() const { return _userName; }
};