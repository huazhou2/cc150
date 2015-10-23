#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool is_Permutation(const string&);
int main() {
	//test cases
	string s("Tact Coa");
	cout<<s<<"\t"<<(is_Permutation(s)?"Yes":"No")<<endl;
	s="Tact Coah";
	cout<<s<<"\t"<<(is_Permutation(s)?"Yes":"No")<<endl;
	}

bool is_Permutation(const string& s) {
	int count=0; //count of odd letter
	unordered_map<char,int> map;
	for (int i=0;i<s.size();i++) {
		if (s[i]!=' ') {
			char temp=s[i];
			if (temp>'Z') temp=temp-32;//to lower case
			map[temp]++;
			if (map[temp]%2) count++;
			else count--;}
		}
	return count==1 || count==0;
	}
		
	
