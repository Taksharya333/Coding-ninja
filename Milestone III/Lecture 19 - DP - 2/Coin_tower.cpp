#include <vector>
bool BeerusWin(vector<bool> &dp,int n,int x,int y){
    if(n==1 || n==x || n==y)
        return true;
    if(dp[n])
        return dp[n];  
    if(n>x && n>y)
        dp[n]=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y) || !BeerusWin(dp,n-y,x,y);
    else if(n>x && n<y)
        dp[n]=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y);
    else if(n<x && n>y)
        dp[n]=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-y,x,y);
    else
        dp[n]=!BeerusWin(dp,n-1,x,y);
    return dp[n];
}
string findWinner(int n, int x, int y)
{
	// Write your code here .
	   vector<bool> dp(n+1,false);
    if(BeerusWin(dp,n,x,y))
        return "Beerus";
    else
        return "Whis";
}