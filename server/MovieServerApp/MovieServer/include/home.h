#pragma once
#include "../httplib.h"

void handle_home(httplib::Request& req, httplib::Response& res);

class Home {
public:
	const char* userName;
	const char* userMovieQuery;

	Home(){}
	~Home(){}

	const const char* GetUserName() const { return userName; }
};