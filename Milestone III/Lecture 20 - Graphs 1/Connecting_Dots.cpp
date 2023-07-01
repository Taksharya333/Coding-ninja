

bool helper(vector<vector<char>> &board,int row, int col, int i, int j,int n, int m,   vector<vector<bool>>& vis,char c,int count)
{
    if(row==i&&col==j && count>=4)return true;
    if(row<0||row>=n)return false;
    if(col<0||col>=m)return false;
    if(board[row][col]!=c)return false;
    if(vis[row][col])return false;
    vis[row][col]=true;
    bool ans= helper(board,row+1,col,i,j,n,m,vis,c,count+1)||helper(board,row-1,col,i,j,n,m,vis,c,count+1)||
    helper(board,row,col-1,i,j,n,m,vis,c,count+1)||helper(board,row,col+1,i,j,n,m,vis,c,count+1);
    vis[row][col]=false;
    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        { 
            if(!vis[i][j])
            if(helper(board,i,j,i,j,n,m,vis,board[i][j],0))return true;
            vis[i][j]=true;
        }
    }
    return false;
}