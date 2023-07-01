#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& vec,int x, int y, int n)
{
    for(int i=y;i>=0;i--)
    if(vec[x][i]==1)return false;
    int row=y;
    int col =x;
    while(row>=0 && col>=0)
    {
        if(vec[col][row]==1)return false;
        row--;
        col--;
    }
    row=y;
    col =x;
    while(row>=0 && col<n)
    {
        if(vec[col][row]==1)return false;
        row--;
        col++;
    }
    return true;
}
void checker(vector<vector<int>>& vec,int y, int n)
{
    if(y>=n)
    {
        for(int i=0;i<n;i++)
        for (int j = 0; j < n; j++) 
        cout << vec[j][i] << ' ';
        cout<<endl;
        return;
    }
for(int i=0;i<n;i++)
{
    if(isSafe(vec,i,y,n))
    {
        vec[i][y]=1;
        checker(vec,y+1,n);
        vec[i][y]=0;
    }
}
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    if(n==2 || n==3)return 0;
    vector<vector<int>> vec(n, vector<int>(n,0));
    checker(vec,0,n);
    return 0;
}