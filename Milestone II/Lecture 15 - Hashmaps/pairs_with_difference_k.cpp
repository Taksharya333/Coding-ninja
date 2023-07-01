#include<bits/stdc++.h>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	unordered_map <int,int>map;
	for(int i=0;i<n;i++)
	map[arr[i]]++;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		unordered_map<int,int>::iterator inter= map.find(k+arr[i]);
		if(inter !=map.end() &&inter->first==arr[i]){
			while( map[arr[i]]--)
			ans+=map[arr[i]];
			map.erase(arr[i]);
			continue;
		}
		
		 if(inter !=map.end())
		{
            ans+=inter->second*map[arr[i]];
			map.erase(arr[i]);
		}
	}
	return ans;
}