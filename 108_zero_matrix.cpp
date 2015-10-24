#include <iostream>
#include <vector>
using namespace std;

void zero_Mat(vector<vector<int> >&);
void print(vector<vector<int> >&);

int main() {
	//test cases
	vector<vector<int> > 
	image={{1,2,3,0},{5,6,7,8},{9,10,11,12}};
	cout<<"Before:"<<endl;
	print(image);
	zero_Mat(image);
	cout<<"After:"<<endl;
	print(image);
	}
//left rotate 90 degrees
void zero_Mat(vector<vector<int> >& board) {
	if (board.empty() || board[0].empty()) return;
	//check first row and col has zero
	bool zero_row=false, zero_col=false;
	for (int i=0;i<board.size();i++) 
		if (board[i][0]==0) {
			zero_col=true;
			break;}
	for (int j=0;j<board[0].size();j++) 
		if (board[0][j]==0) {
			zero_row=true;
			break;}
	//use first row and col to store zero col and row
	for (int i=1;i<board.size();i++) 
		for (int j=1;j<board[i].size();j++) {
			if (!board[i][j]) {
			board[i][0]=0;
			board[0][i]=0;
			}
	}
	//set row as 0
	for (int i=1;i<board.size();i++) 
		if (!board[i][0]) {
			for (int j=0;j<board[i].size();j++)
				board[i][j]=0;
			}
	//set col as  0
	for (int j=1;j<board[0].size();j++) 
		if (!board[0][j]) {
			for (int i=0;i<board.size();i++)
				board[i][j]=0;
			}
	//set first row as 0 if necessary
	if (zero_row) 
		for (int j=0;j<board[0].size();j++)
			board[0][j]=0;
	//set first col as 0 if necessary
	if (zero_col) 
		for (int i=0;i<board.size();i++)
			board[i][0]=0;
	}
void print(vector<vector<int> >& board) {
	if (board.empty() || board[0].empty()) return;
	for (int i=0;i<board.size();i++) 
		for (int j=0;j<board[i].size();j++) 
			if (j==board[i].size()-1)
				cout<<board[i][j]<<endl;
			else 
				cout<<board[i][j]<<"  ";
}	
