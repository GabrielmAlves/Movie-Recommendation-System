#pragma once
#include <iostream>
#include <unordered_map>

class User {
private:
	const std::string _userName;
	const std::string _userEmail;
	const std::string _userAppName;
	std::string _userPassword;
public:
	short userAge;
	std::unordered_map<std::string, std::string> userMoviePreferences;

	User(std::string userName, std::string userAppName,
		std::string userEmail, std::string userPassword) : 
		_userName(userName), _userEmail(userEmail), _userAppName(userAppName), _userPassword(userPassword)
	{}
};