#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    int sum=0;
     unordered_map<int,int>map;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        arr[i]=sum;
        if(map[sum]==0)
        map[sum]=i+1;
    }
     map[0]=0;
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans, i+1-map[arr[i]]);
     return ans;
}