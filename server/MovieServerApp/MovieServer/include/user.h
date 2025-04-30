#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

class User {
private:
	const std::string _userName;
	const std::string _userEmail;
	const std::string _userAppName;
	std::string _userPassword;
public:
	short userAge;
	std::unordered_map<std::string, std::string> userMoviePreferences;
	std::vector<std::string>* userMovieGenrePreferences;

	User(std::string userName, std::string userAppName,
		std::string userEmail, std::string userPassword, std::vector<std::string>* moviePreferences) :
		_userName(userName), _userEmail(userEmail), _userAppName(userAppName), _userPassword(userPassword),
		userMovieGenrePreferences(moviePreferences)
	{}

	const std::string& getUserName() const { return _userName; }
	const std::string& getUserEmail() const { return _userEmail; }
	const std::string& getUserAppName() const { return _userAppName; }
	const std::string& getUserPassword() const { return _userPassword; }
};