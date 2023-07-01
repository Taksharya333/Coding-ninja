#include<unordered_map>
#include<bits/stdc++.h>
int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map <int,int>map;
	if(n<2)return n;
	for(int i=0;i<n;i++)
	map[arr[i]]++;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0){
			while(map[arr[i]]--)
			ans+=map[arr[i]];
			map.erase(arr[i]);
			continue;
		}
		unordered_map<int,int>::iterator inter= map.find(-arr[i]);
		
		 if(inter !=map.end())
		{
            ans+=inter->second*map[arr[i]];
			map.erase(inter);
			map.erase(arr[i]);
		}
	}
	return ans;
}