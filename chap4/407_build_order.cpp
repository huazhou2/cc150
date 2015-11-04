#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;
void helper(list<pair<char,char> >& condition, unordered_map<char,int>& visited,stack<char>& result, list<char>& obj,char cur) {
		if (!visited[cur]) {
		for (list<pair<char,char> >::iterator it=condition.begin();it!=condition.end();it++) 
			if (it->first==cur && !visited[it->second]) 
				helper(condition,visited,result,obj,it->second);
		result.push(cur);	
		visited[cur]=1;
		}}
vector<char> buildOrder(list<pair<char,char> >& condition, list<char>& obj) {
	vector<char> result;
	if (obj.empty()) return result;
	stack <char> sta;
	unordered_map<char,int> visited;
	for (list<char>::iterator it=obj.begin();it!=obj.end();it++) 
		visited[*it]=0; 
	for (list<char>::iterator it=obj.begin();it!=obj.end();it++)
		helper(condition,visited, sta, obj, *it);
		
	while (!sta.empty()) {
		result.push_back(sta.top());
		sta.pop();
		}
	return result;}

void print(vector<char>& result) {
	if (!result.empty()){ 
		for (int i=0;i<result.size();i++) 
			cout<<result[i]<<"  ";
		cout<<endl;}
		}
int main() {
	list<char> obj;
	obj.push_back('a');
	obj.push_back('b');
	obj.push_back('c');
	obj.push_back('d');
	obj.push_back('e');
	obj.push_back('f');
	list<pair<char,char> > condition;
	condition.push_back(std::make_pair<char,char>('d','a'));
	condition.push_back(std::make_pair<char,char>('b','f'));
	condition.push_back(std::make_pair<char,char>('d','b'));
	condition.push_back(std::make_pair<char,char>('a','f'));
	condition.push_back(std::make_pair<char,char>('c','d'));
	vector<char> result=buildOrder(condition,obj);
	print(result);
	}

