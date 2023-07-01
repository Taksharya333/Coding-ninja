//code is not optimized and gives O(n^2) time complexity in worst case when the elements in the array are in descending order.
#include<bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int mini=INT_MAX, maxi=INT_MIN;
    unordered_map<int, int>map;
    vector<int> vec;
    for(int i=0;i<n;i++) map[arr[i]]=1;
    int point=0;
    int left,right;
   for(int i=0;i<n;i++)
   {
       if(map[arr[i]]==1)
       {
           int size =0;
           int j=arr[i];
           while(map[j]==1)
           {
               j++;
               size++;
           }
            if(point<size)
            {
                point=size;
                left=arr[i];
                right=j-1;
            }
       }
   }
   vec.push_back(left);
   if(left==right)return vec;
   else{
       vec.push_back(right);
       return vec;
   }
}