#include "Progress.hpp"

Progress::Progress()
{
	WPM = 0;
	username = "";
}

Progress::Progress(string _id)
{
	username = _id;
	profile_path = "../../KeyboardWarriorsTypingTestApp/User_Profiles/" + username + ".txt";
}

Progress::~Progress()
{

}

Result Progress::locateResult(string res)
{
	Result r = Result();
	//FOUND
	if (Results.find(res) != Results.end())
	{
		return Results[res];
	}
	else
	{
		throw invalid_argument("Unable to find the Result: " + res + "\n");
	}
	return r;
}

bool Progress::read_profile()
{
	string line;
	ifstream file(profile_path);
	bool history = false;
	if (!file.is_open())
	{
		cerr << "Unable to Find Profile for " << username << endl;
		return false;
	}
	else
	{
		while (getline(file, line))
		{
			//SEARCHING FOR WPM 
			//not the correct string to find
			size_t found = line.find("WPM");
			if (found != string::npos)
			{
				// "WPM": <-3 spaces + 1 space to get to the number
				int increase_index = 4;
				found = found += increase_index;
				//find WPM and convert from string to float
				WPM = stof(line.substr(found, line.size() - 1));
			}
			//SEARCHING PAST RESULTS
			found = line.find("history");
			if (!history)
			{
				if (found != string::npos)
					history = true;
			}
			//history part
			else
			{
				string lineNext;
				while (getline(file, lineNext))
				{
					//reading history
					found = line.find("\\");
					if (found != string::npos)
					{
						string session_id = line.substr(0, found);
						found = found + 3;
						float one_wpm = stof(line.substr(found, line.size() - 1));
						cout << "Session ID: " << session_id << endl;
						cout << "WPM: " << one_wpm << endl;
						Results[session_id] = one_wpm;
					}
				}
			}
		}
	}
	return true;
}

double Progress::getAverageWPM()
{
	return WPM;
}