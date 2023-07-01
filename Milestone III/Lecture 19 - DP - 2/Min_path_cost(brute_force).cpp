
void helper(int **input, int i, int j, int m, int n, int val, int & ans)
{
	if(i==m-1 && j==n-1)
	{
		ans= min(ans, val+input[i][j]);
		return;
	}
	else if(i>=m ||j>=n)return;
	helper(input,i+1,j,m,n,val+input[i][j], ans);
	helper(input,i,j+1,m,n,val+input[i][j], ans);
	helper(input,i+1,j+1,m,n,val+input[i][j], ans);
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
	int ans =INT_MAX;
	helper(input,0,0, m, n, 0, ans);
	return ans;

}