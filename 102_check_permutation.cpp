#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool is_Permutation(const string&, const string&);

int main() {
	//test cases
	string s1("huazhou");
	string s2("zhouhua");
	string s3("hhhhhhh");
	cout<<s1 <<"\t"<<s2<<"\t"<<(is_Permutation(s1,s2)?"Yes":"no")<<endl;
	cout<<s1 <<"\t"<<s3<<"\t"<<(is_Permutation(s1,s3)?"Yes":"no")<<endl;
	}
bool is_Permutation(const string& s1, const string& s2) {
	if (s1.size()!=s2.size()) return false;
	unordered_map<char,int> map;
	for (int i=0;i<s1.size();i++) 
		map[s1[i]]++;
	for (int i=0;i<s2.size();i++) {
		unordered_map<char,int>::iterator it=map.find(s2[i]);
		if (it==map.end()) return false;
		else { 
			it->second--;
			if (it->second<0) return false;
			}
		}
	return true;
	}
