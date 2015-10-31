#include <iostream>
#include <vector>
using namespace std;

void rotate_Matrix(vector<vector<int> >&);
void print(vector<vector<int> >&);

int main() {
	//test cases
	vector<vector<int> > image(4,vector<int>(4,0));
	int count=0;
	for (int i=0;i<image.size();i++) 
		for (int j=0;j<image[i].size();j++) 
			image[i][j]=++count;
	cout<<"Before:"<<endl;
	print(image);
	rotate_Matrix(image);
	cout<<"After:"<<endl;
	print(image);
	}
//left rotate 90 degrees
void rotate_Matrix(vector<vector<int> >& board) {
	if (board.empty() || board[0].empty()) return;
	//upper left to bottorm right mirroring
	int b_size=board.size();
	for (int i=0;i<b_size-1;i++) 
		for (int j=i+1;j<b_size;j++) {
			int temp=board[i][j];
			board[i][j]=board[j][i];
			board[j][i]=temp;
			}
	//up-down mirroring
	for (int i=0;i<b_size/2;i++) 
		for (int j=0;j<b_size;j++) {
			int temp=board[i][j];
			board[i][j]=board[b_size-i-1][j];
			board[b_size-i-1][j]=temp;
			}
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
	




	
