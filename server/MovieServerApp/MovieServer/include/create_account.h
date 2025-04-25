#pragma once
#include "../httplib.h"
#include "user.h"
#include <string>
#include <unordered_map>

void handle_signup(const httplib::Request& req, httplib::Response& res);

class CreateAccount {
public:
	void CreateUserAccount(User& user);
};