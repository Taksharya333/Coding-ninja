#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
	int n;
	cin>>n;
	int *arr= new int[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int sum=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum<=0)sum=0;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}