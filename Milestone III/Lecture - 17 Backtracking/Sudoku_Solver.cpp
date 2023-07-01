#include<bits/stdc++.h>
using namespace std;

bool rowchecker(vector<vector<int>>& grid,int col,int val)
{
  for(int i=0;i<9;i++)
  {
    if(grid[i][col]==val)return false;
  }
  return true;
}
bool columnchecker(vector<vector<int>>& grid, int row,int val)
{
 for(int i=0;i<9;i++)
  {
    if(grid[row][i]==val)return false;
  }
  return true;
}
bool blockchecker(vector<vector<int>>& grid, int row,int col, int val)
{
  int blockrow= row-(row%3);
  int blockcol= col-(col%3);
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
        if(grid[blockrow+i][blockcol+j]==val)return false;
    }
  }
  return true;
}
bool sudokusolver(vector<vector<int>>& grid)
{
   for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(grid[i][j]==0)
      {
        for(int c=1;c<10;c++)
        {
          if(rowchecker(grid,j,c) && columnchecker(grid,i,c)&& blockchecker(grid,i,j,c))
          {
            grid[i][j]=c;
              if(sudokusolver(grid))return true;
               grid[i][j]=0;
          }
        }
        return false;
      }
    }
  }
  return true;
}
int main(){
    
    // write your code here
   vector<vector<int>> grid(9,vector<int>(9,0));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>> grid[i][j];
        }
    }
    if (sudokusolver(grid)) {
    //    for(int i=0;i<9;i++){
    //   for (int j = 0; j < 9; j++) {
    //     cout<<grid[i][j]<<' ';
    //   }
    //   cout<<endl;
    // }
      cout << "true";
    } else
      cout << "false";
    return 0;
}