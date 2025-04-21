#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Login {
private:
	const std::string _userName;
	const std::string _userEmail;
	std::unordered_map <std::string, std::string> _userMoviePreferences;
	std::unordered_map <std::string, std::string> _userChosenMovies;
public:
	short userAge;

	void createAccount(std::string userName, std::string userEmail, std::string userPassword);
};