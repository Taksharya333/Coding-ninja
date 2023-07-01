#include<math.h>
#include <vector>

int helper(int a,int b,int curr, vector<int>&output)
{
	if(a<0)
    {
        return 0;
    }
    if(a==0)
    {
        return 1;
    }
    int ans=0; 
    for(int i=curr;pow(i,b)<=a;i++)
    {
        ans += helper(a-pow(i,b),b,i+1,output);
    }
    output[a]=ans;
    return ans;
}

int getAllWays(int a, int b) {
	// Write your code here
    vector<int>output(a+1,-1);
    return helper(a,b,1,output);
}