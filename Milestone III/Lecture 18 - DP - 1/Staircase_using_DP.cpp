#include<bits/stdc++.h>
using namespace std;
long long helper(int n,long long * arr)
{
	  if(n==0)return 0;
    else if(n<3 )return n;
    else if(n==3)return 4;
	if(arr[n]!=-1)return arr[n];
	arr[n]= (helper(n-3,arr)+helper(n-2,arr)+helper(n-1,arr))%1000000007;
	return arr[n];
}
long long staircase(int n)
{
	//Write your code here
	long long arr[n+1];
	for(int i=0;i<=n;i++)arr[i]=-1;
	return helper(n,arr);	
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<staircase(n)%1000000007<<endl;
    }
    return 0;
}