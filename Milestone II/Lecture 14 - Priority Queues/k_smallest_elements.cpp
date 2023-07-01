#include<bits/stdc++.h>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;
    if(k>=n)
    {
        for(int i=0;i<n;i++)
        ans.push_back(arr[i]);
        return ans;
    }
    priority_queue<int> q;
    for(int i=0;i<k;i++)
    q.push(arr[i]);
    for(int i=k;i<n;i++)
    {
        if(arr[i]<q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}