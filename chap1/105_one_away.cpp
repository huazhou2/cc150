#include <string>
#include <iostream>
using namespace std;

bool one_Away(const string&, const string&);

int main() {
	//test cases;
	string s1("pale"),s2("ple"),s3("pales"),s4("bale"),s5("bake");
	cout<<s1<<", "<<s2<<" -> "<<(one_Away(s1,s2)?"True":"False")<<endl;
	cout<<s3<<", "<<s1<<" -> "<<(one_Away(s3,s1)?"True":"False")<<endl;
	cout<<s1<<", "<<s4<<" -> "<<(one_Away(s1,s4)?"True":"False")<<endl;
	cout<<s1<<", "<<s5<<" -> "<<(one_Away(s1,s5)?"True":"False")<<endl;
	}

bool one_Away(const string& s1,const string& s2) {
	if (s1.empty()) return s2.size()==1;
	else if (s2.empty()) return s1.size()==1;
	int min_size=s1.size()>s2.size()?s2.size():s1.size();
	if (s1[0]==s2[0]) return one_Away(s1.substr(1),s2.substr(1));
	else return (s1.substr(1)==s2 || s1==s2.substr(1) || s1.substr(1)==s2.substr(1));
	}
		

