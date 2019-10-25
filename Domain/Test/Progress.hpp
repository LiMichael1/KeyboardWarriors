#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "Result.hpp"
using namespace std;
class Progress
{
	private:
		map<string, Result> Results;
		string username;
		string profile_path;
		float WPM;
	public:
	  Progress();
	  Progress(string);
	  bool read_profile();
	  ~Progress();
	  Result locateResult(string);
	  double getAverageWPM();
	 
};