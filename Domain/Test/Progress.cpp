#include "Progress.hpp"

Progress::Progress()
{
	WPM = 0;
	number_of_sessions = 0;
	username = "";
	profile_path = "";
}

Progress::Progress(string _id)
{
	WPM = 0;
	number_of_sessions = 0;
	username = _id;
	profile_path = "../../KeyboardWarriorsTypingTestApp/User_Profiles/" + username + ".txt";
	if (!read_profile())
		throw invalid_argument("Profile does not exist in database.\n");
	else
		cout << "Welcome Back, " << username << endl;
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
			size_t found = line.find("WPM\\");
			if (found != string::npos)
			{
				// WPM\\ <-5 spaces 
				int increase_index = 5;
				found = found += increase_index;
				//find WPM and convert from string to float
				WPM = stof(line.substr(found, line.size()));
				//cout << "Average WPM: " << WPM << endl;
			}
			//SEARCHING PAST RESULTS
			found = line.find("history");
			if (!history)
			{
				if (found != string::npos)
					history = true; //will record next lines in the loop
			}
			//history part
			if(history)
			{
				string lineNext;
				while (getline(file, lineNext))
				{
					//reading history
					found = lineNext.find("\\");
					if (found != string::npos)
					{
						string session_id = lineNext.substr(0, found);
						found = found + 2;
						float one_wpm = stof(lineNext.substr(found, lineNext.size() - 1));
						/*cout << "Session ID: " << session_id << endl;
						cout << "WPM: " << one_wpm << endl;*/
						Results[session_id] = one_wpm;
						total_WPM += one_wpm;
						number_of_sessions += 1;
					}
				}
			}
		}
		file.close();
	}
	return true;
}

float Progress::getAverageWPM()
{
	return WPM;
}

void Progress::updateResults(string session_ID, Result res)
{
	number_of_sessions += 1;
	Results[session_ID] = res;
	total_WPM += res.getWPM();
	WPM = total_WPM / number_of_sessions;
}

void Progress::print_results()
{
	map<string, Result>::iterator it = Results.begin();
	cout << "Results" << endl;
	while (it != Results.end())
	{
		cout << "Session ID: " << it->first << endl;
		cout << "WPM: " << it->second.getWPM() << endl << endl;

		it++;
	}
	cout << endl;
}