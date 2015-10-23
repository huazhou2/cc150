#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string Compression(string& s);
string int2str(int);
int main() {
	//test cases
	string s("aabcccccaaa");
	cout<<"before:  "<<s<<endl;
	cout<<"after:   "<<Compression(s)<<endl;
	s="aaaaaaaaaaaaaaaaaaaaaaabbb";
	cout<<"before:  "<<s<<endl;
	cout<<"after:   "<<Compression(s)<<endl;
	}
string Compression(string& s) {
	if (s.empty()) return s;
	s=s+' ';
	//check if size larger than original after compression
	int count=0;
	char cur=' ';
	int temp_count=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]!=cur) {
		count++;
		while (temp_count) {
			temp_count=temp_count/10;
			count++;}
		temp_count=1;
		cur=s[i];}
		else 
		temp_count++;
		}
	//if really compressed, do the compression by creating new string
	if (count<=s.size()-1) {
		string result("");
		cur=s[0];
		temp_count=1;
		for (int i=1;i<s.size();i++) {	
			if (s[i]!=cur) {
			result=result+cur+int2str(temp_count);
			temp_count=1;
			cur=s[i];
			}
			else temp_count++;
		}
		return result;
		}
	else {
		s=s.substr(0,s.size()-1);
		return s;}
	}
//transform a non-negative number to string
string int2str(int num) {
	assert(num>=0);//assert if number is non-negative
	string res("");
	while (num) {
		char rem=num%10+'0';
		num=num/10;
		res=rem+res;
		}
	return res;
	}

			
				
	
		
