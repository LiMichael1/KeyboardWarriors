#pragma once

#include <map>
#include <string>
#include <fstream>
#include "Result.hpp"
using namespace std;
class Progress
{
	private:
	  string id;
	public:
	  Progress();
	  Progress(string);
	  ~Progress();
	  Result locateResult(std::string);
	  double getAverageWPM();

};