#include<bits/stdc++.h>
using namespace std;
void fillerrow(vector<vector<char>>& grid,int row, int col,string c, vector<bool>&a)
{
 int size = c.length();
 for(int j=0;j<size;j++)
  {
       if(grid[row+j][col]=='-')a[j]=true;
    grid[row+j][col]=c[j];
  }      
}


void fillercol(vector<vector<char>>& grid,int row, int col,string c, vector<bool>&a)
{
 int size = c.length();
 for(int j=0;j<size;j++)
  {
       if(grid[row][col+j]=='-')a[j]=true;
    grid[row][col+j]=c[j];
  }      
}


void removerrow(vector<vector<char>>& grid,int row, int col,string c, vector<bool>&a)
{
   int size = c.length(); 
  for(int j=0;j<size;j++) if(a[j])grid[row+j][col]='-';      
}


void removercol(vector<vector<char>>& grid,int row, int col,string c, vector<bool>&a)
{ 
   int size = c.length(); 
  for(int j=0;j<size;j++) if(a[j])grid[row][col+j]='-';      
}


bool rowchecker(vector<vector<char>>& grid,int row, int col,string c)
{
    int size = c.length();
    for (int j = 0; j < size; j++) {
        if(row+j>9)return false;
      if (grid[row+j][col] == '+')
        return false;
      if (grid[row+j][col] != '-' && grid[row+j][col] != c[j])
        return false;
    }
     if( row+size>9 || grid[row+size][col]=='+')return true;
    return false;
}


bool colchecker(vector<vector<char>>& grid,int row, int col,string c)
{
      int size = c.length();
    for (int j = 0; j < size; j++) {
        if(col+j>9)return false;
      if (grid[row][col+j] == '+')
        return false;
      if (grid[row][col+j] != '-' && grid[row][col+j] != c[j])
        return false;
    }
     if(col+size>9 || grid[row][col+size]=='+')return true;
    return false;
}


void print(vector<vector<char>>& grid)
{
 for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        cout<<grid[i][j];
        cout<<endl;
    }
}


bool solver(vector<vector<char>>& grid,int row,int col, queue<string>& q)
{
  if (q.empty()) {
   print(grid);
    return true;
  }
for(int i=col;i<10;i++)
{
    if(grid[row][i]!='+')
    {
        int size=q.size();
        while(size--)
        {
            string temp= q.front();
            q.pop();
            vector<bool>a(temp.length(),false);
            if(rowchecker(grid,row,i,temp))
            {
                fillerrow(grid,row,i,temp,a);
                if (!solver(grid, row, i + 1, q)) 
                  removerrow(grid, row, i, temp,a);
                 else
                  return true;
            }
          else if(colchecker(grid,row,i,temp))
            {
                fillercol(grid,row,i,temp,a);
                if (!solver(grid, row, i + 1, q)) 
                  removercol(grid, row, i, temp,a);
                 else
                  return true;
            }
            q.push(temp); 
        }
        if(grid[row][i]=='-')return false;
    }
}
return solver(grid,row+1,0,q);
}


int main(){
    
    // write your code here
    vector<vector<char>> grid(10, vector<char>(10));
    for(int i=0;i<10;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<10;j++)
        grid[i][j]=s[j];
    }
    string w;
    cin>>w;
    queue<string> q;
    int len= w.length();
    string temp="";
    for(int i=0;i<len;i++)
    {
        if(w[i]==';')
        {
            q.push(temp);
            temp="";
        }
        else temp+=w[i];
    }
    q.push(temp);
    solver(grid,0,0,q);
    return 0;
}