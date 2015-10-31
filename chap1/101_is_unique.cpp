#include <iostream>
#include <string>
using namespace std;
//suppose only lower case, then I can use a byte: 32 bit

bool is_Unique(const string&);

int main() {
	//test cases
	string s1("hua zhou");
	string s2("efghi abc");
	//parenthesis is needed here!
	cout<<s1<<" is "<<(is_Unique(s1)?"":"not ")<<"unique"<<endl;
	cout<<s2<<" is "<<(is_Unique(s2)?"":"not ")<<"unique"<<endl;
	}
bool is_Unique(const string& s) {
	int bit=0;
	for (int i=0;i<s.size();i++) {
		int bit_rep=1<<static_cast<int>(s[i]-'a');
		if (bit_rep & bit) return false;
		else bit=bit|bit_rep;
		}
	return true;
	}
		

