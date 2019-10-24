#include "Session.hpp"

Session::Session()
{
    date = getTimeStr();
    string username = "";
    //do you need the dynamically allocate.
    TypingTest = Test(); //overload = operator? for Test Objects
    test_content = "";
    TimeTaken = 0;
}


Session::~Session()
{

}

void Session::StartSession()
{
    if (test_content == "")
    {
        throw invalid_argument("Test is empty!\n");
    }
    else
    {
        
    }
}

Result Session::getTestResults()
{
    //update Results to know what this means.
}

void Session::selectTest(Difficulty::Level difficulty)
{
    TypingTest = Test(difficulty);
    test_content = TypingTest.getContent();
}

//get time and date
string getTimeStr()
{
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    string s(30, '\0');
    strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return s;
}