#pragma once
#include "../Test/Test.hpp"
#include "../Test/Result.hpp"
#include "../Test/Difficulty.hpp"
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;
class Session
{
private:
  string username;
	string date;
	string SesssionID;
	Test TypingTest;
	double TimeTaken;
  string test_content;

public:
  Session();
  Session(string username);
  ~Session();
  void StartSession();
  Result getTestResults();
  void selectTest(Difficulty::Level difficulty);

};
