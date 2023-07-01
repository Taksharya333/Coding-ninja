#include<bits/stdc++.h>
int helper(string s1, string s2,int i, int j,int m, int n)
{
	if(i==m||j==n)return abs((m-i)-(n-j));
     if (s1[i] == s2[j]) {
       return helper(s1, s2, i + 1, j + 1,m,n);
        } 
		else
          return 1 + min(helper(s1, s2, i + 1, j,m,n), min(helper(s1, s2, i, j + 1,m,n), helper(s1, s2, i + 1, j + 1,m,n)));
}
int editDistance(string s1, string s2) {
	// Write your code here
	int m=s1.length(),n=s2.length();
	return helper(s1,s2,0,0,m,n);
}