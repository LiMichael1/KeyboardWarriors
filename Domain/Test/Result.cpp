#include "Result.hpp"

string user_profiles_directory = "../KeyboardWarriorsTypingTestApp/User_Profiles/";

Result::Result()
{
    WPM = 0; 
    username = "";
    sessionID = "";
}

Result::Result(int words, int sec, string _username, string _sessionID)
{
    WPM = float((words/sec)*(60/1)); 
    username = _username;
    sessionID = _sessionID;
}

Result::~Result()
{

}

void Result::updateResults()
{
    
}

vector<string> Result::viewResults()
{
    string path_to_user_profile = user_profiles_directory + username + ".txt";
    //check if correct
    cout << path_to_user_profile << endl;

    ifstream file(path_to_user_profile);
    string line;

    vector<string> res; 
    if (!file.is_open())
    {
        cerr << "Results file could not be located. \n";
    }
    else
    {
        while (getline(file, line))
        {
            res.push_back(line);
        }
    }
    return res;
}   
