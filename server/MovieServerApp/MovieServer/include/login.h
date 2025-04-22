#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Login {
private:
	const std::string _userName;
	std::string _userPassword;
public:
	void UserLogin(std::string userName, std::string userPassword);
};