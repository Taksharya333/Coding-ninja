#include<queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==0)return;
    else if(n==1){
        cout<<arr[0];
        return;
    }
    priority_queue<int> q1;
    priority_queue<int, vector<int>,greater<int>>q2;
    q1.push(min(arr[0],arr[1]));
    q2.push(max(arr[0],arr[1]));
    cout<<arr[0]<<' '<<(arr[0]+arr[1])/2<<' ';
    for(int i=2;i<n;i++)
    {
        if(i%2==1)
        {
            if(arr[i]<q1.top())
            q1.push(arr[i]);
            else q2.push(arr[i]);
            while(q2.size()!=q1.size())
            {
                if(q2.size()>q1.size())
                {
                    q1.push(q2.top());
                    q2.pop();
                }
                else{
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            cout<<(q1.top()+q2.top())/2<<' ';
        }
        else{
              if(arr[i]<q1.top())
            q1.push(arr[i]);
            else q2.push(arr[i]);
            while(q2.size()+1!=q1.size())
            {
                if(q2.size()+1>q1.size())
                {
                    q1.push(q2.top());
                    q2.pop();
                }
                else{
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            cout<<q1.top()<<' ';
        }
    }
}