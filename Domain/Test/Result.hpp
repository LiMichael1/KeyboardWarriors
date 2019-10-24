#pragma once
#include "../Sessions/Session.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Result
{
private:
	float WPM;
	std::string username;
	std::string sessionID;
public:
	Result();
	Result(int, int, string, string);
	~Result();
	vector<string> viewResults();
	void updateResults();
};
