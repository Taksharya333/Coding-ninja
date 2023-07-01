#include<bits/stdc++.h>
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if(maxWeight==0)return INT_MIN;
	if(n==0)return 0;
	return max(values[0]+knapsack(weights+1, values+1, n-1,maxWeight-weights[0]),knapsack(weights+1, values+1, n-1,maxWeight));
}