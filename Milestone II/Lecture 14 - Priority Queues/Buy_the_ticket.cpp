#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    priority_queue<int>q;
    queue<pair<int,int>>que;
    for(int i=0;i<n;i++)
     {
      q.push(arr[i]);
      que.push({arr[i], i});
    }
    int ans=0;
    while(true)
    {
       if(que.front().first==q.top())
       {
           ans++;
            if(que.front().second==k)break;
            q.pop();
            que.pop();
       }
       else{
           pair<int,int> temp= que.front();
           que.pop();
           que.push(temp);
       }
    }
    return ans;
}