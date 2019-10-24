#include "User.hpp"
#include <string>
#include <vector>
using namespace std;

User::User()
{
	username = "";
	password = "";
	membership = false;
	
}

User::~User()
{

}
// New User
bool User::getMembership() {
	return membership;
}
void User::setMembership(bool isMember) {
	membership = isMember;
}
string User::getUsername() {
	return username;
}
void User::changePassword(string new_pw)
{
	password = new_pw;
}

bool User::makePayment()
{

}

Session User::requestTypingTest()
{
	Session s(getUsername());
	try{
		s.StartSession();
	}
	catch(const exception &ex)
	{
		cerr << ex.what() << endl;
	}
}


// vector<string> User::getOptions() {
// 	vector<string> options;
// 	options.push_back("View Personal Progress");

// }
