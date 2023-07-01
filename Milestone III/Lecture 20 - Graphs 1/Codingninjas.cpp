

bool helper(vector<vector<char>> &board,int row,int col, int n, int m, int index,vector<vector<bool>>& vis,string& s)
{
    if(index==s.length())return true;
     if(col<0||col>=m)return false;
    if(row<0||row>=n)return false;
    if(vis[row][col])return false;
    if(board[row][col]!=s[index])
     return false;
    vis[row][col]=true;
    int arr[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    bool ans=false;
    for(int i=0;i<8;i++)
    {
        ans=ans||helper(board, row+arr[i][0],col+arr[i][1],n,m,index+1,vis,s);
        if (ans) {
             vis[row][col]=false;
          return true;
        }
    }
     vis[row][col]=false;
   return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
     string s="CODINGNINJA";
    int size = s.length();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          if (board[i][j] == 'C') {
            if (helper(board, i, j, n, m, 0, vis, s))
              return true;
          }
        }
    }
    return false;
}