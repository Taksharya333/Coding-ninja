#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    int size= input.size();
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<size;i++)
    {
        int tempsize=input[i]->size();
        for(int j=0;j<tempsize;j++)
        q.push((*input[i])[j]);
    }
    vector<int> ans;
    while(!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}