/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void fillin(vector<vector<int>>& ques,vector<vector<int>>& ins,int x, int y, int n)
{
if(x>=n || x<0 || y>=n || y<0||ques[x][y]==0 || ins[x][y]==1)return;
ins[x][y]=1;
if( x==n-1 && y==n-1)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cout<<ins[i][j]<<' ';
	cout<<endl;
	ins[x][y]=0;
	return;
}

int arr[4][2] = { {1,0} ,{-1,0}, {0,1}, {0,-1} };
for (int i = 0; i < 4; i++) fillin(ques,ins, x + arr[i][0], y + arr[i][1], n);
  ins[x][y]=0;
}
int main() {

	// Write your code here
	int n;
	cin>>n;
	vector<vector<int>> ques(n, vector<int>(n,0));
	int val;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>val;
		ques[i][j]=val;
	}
	vector<vector<int>> ans(n, vector<int>(n,0));
	fillin(ques, ans,0,0,n);
	return 0;
}
