#include <iostream>
#include <string>
using namespace std;

void urify(string&,int);

int main () {
	//test cases,at end of string, enough spaces(may be
	//more than needed for in place operation
	string s("Mr John Smith    ");
	cout<<s<<endl;
	urify(s,13);
	cout<<s<<endl;
	}
	
void urify(string& s, int length) {
	int count=1;
	for (int i=length-1;i>=0;i--) {
		if (s[i]!=' ') 
		s[s.size()-count++]=s[i];
		else {
		s[s.size()-count++]='0';
		s[s.size()-count++]='2';
		s[s.size()-count++]='%';
			}
	}
	}
		
	
