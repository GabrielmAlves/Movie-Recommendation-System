#pragma once
#include <string>
#include <unordered_map>

class CreateAccount {
private:
	const std::string _userName;
	const std::string _userEmail;
	std::string _userPassword;
public:
	short userAge;
	std::unordered_map<std::string, std::string> userMoviePreferences;

	void CreateUserAccount(std::string userName, std::string userEmail, std::string userPassword);
};