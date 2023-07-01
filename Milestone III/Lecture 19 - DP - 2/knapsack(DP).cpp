#include<vector>
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	vector<vector<int>>dp(n+1,vector<int>(maxWeight+1));
	for(int i=0;i<=maxWeight;i++)
	dp[0][i]=0;
	for(int i=0;i<=n;i++)
	dp[i][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=maxWeight;j++)
		{
			if(weight[i-1]>j)dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			else dp[i][j]=max(dp[i-1][j],value[i-1]+ dp[i-1][j-weight[i-1]]);
		}
	}
	return dp[n][maxWeight];
}