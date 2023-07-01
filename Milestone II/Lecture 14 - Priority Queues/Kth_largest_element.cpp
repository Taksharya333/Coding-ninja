#include<bits/stdc++.h>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<k;i++)
    q.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(arr[i]>q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}