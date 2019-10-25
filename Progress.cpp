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

			}
		}
	}
	return true;
}

double Progress::getAverageWPM()
{
	return WPM;
}