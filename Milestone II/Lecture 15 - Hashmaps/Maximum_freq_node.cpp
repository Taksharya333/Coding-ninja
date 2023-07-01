#include<bits/stdc++.h>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> temp;
    int temper=INT_MIN;
    int ans=0;
    for(int i=0;i<n;i++)
    temp[arr[i]]++;
    for (int i=0;i<n;i++) {
     if(temp[arr[i]]>temper)
     {
         temper=temp[arr[i]];
         ans=arr[i];
     }
    }
    return ans;
}