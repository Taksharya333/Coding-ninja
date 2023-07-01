int dfs(vector<vector<int>> &cake,int i, int j, int n, vector<vector<bool>>&vis)
{
    if(i<0|i>=n)return 0;
    if(j<0||j>=n)return 0;
    if(!cake[i][j])return 0;
    if(vis[i][j])return 0;
    vis[i][j]=true;
    return cake[i][j]+dfs(cake,i+1,j,n,vis)+dfs(cake,i-1,j,n,vis)+dfs(cake,i,j+1,n,vis)+dfs(cake,i,j-1,n,vis);
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j])
            ans=max(ans,dfs(cake,i,j,n,vis));
        }
    }
    return ans;
}