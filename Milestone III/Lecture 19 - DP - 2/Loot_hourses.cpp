#include<bits/stdc++.h>

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *h=new int[n];
	if(n>1)h[1]=max(arr[1],h[0]);
	for(int i=2;i<n;i++)
	{
		h[i]=max(arr[i]+h[i-2],h[i-1]);
	}
	return h[n-1];	
}