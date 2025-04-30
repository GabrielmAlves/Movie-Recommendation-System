#pragma once
#include "../httplib.h"
#include <string>

class Login {
private:
	const std::string _userName;
	std::string _userPassword;
public:
	void handle_login(const httplib::Request req, const httplib::Response res);
	void UserLogin(const std::shared_ptr<Login>& loginObjec);

	Login(const std::string username, std::string password) 
		: _userName(username), _userPassword(password) {}

	const std::string GetUsername() const { return _userName; }
};