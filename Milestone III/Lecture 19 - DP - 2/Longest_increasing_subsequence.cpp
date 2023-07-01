#include<bits/stdc++.h>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int l=dp[i+1][j+1];
                if(j==-1 || arr[i]>arr[j]){
                    l=max(l, 1+dp[i+1][i+1]);
                }
                dp[i][j+1]=l;
            }
        }
        return dp[0][0];
}