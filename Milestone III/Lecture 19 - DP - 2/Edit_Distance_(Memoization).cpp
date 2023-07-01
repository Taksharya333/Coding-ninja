#include<bits/stdc++.h>
int helper(string s1, string s2,int i, int j,int m, int n, vector<vector<int>>& h)
{
	if(i==m||j==n)return abs((m-i)-(n-j));
     if(h[i][j]!=-1)return h[i][j];
     if (s1[i] == s2[j]) {
       return helper(s1, s2, i + 1, j + 1,m,n,h);
        } 
		else
          h[i][j]= 1 + min(helper(s1, s2, i + 1, j,m,n,h), min(helper(s1, s2, i, j + 1,m,n,h), helper(s1, s2, i + 1, j + 1,m,n,h)));
          return h[i][j];
}
int editDistance(string s1, string s2)
{
	//Write your code here
     	int m=s1.length(),n=s2.length();
          vector<vector<int>> h(m,vector<int>(n,-1));
	return helper(s1,s2,0,0,m,n,h);
}