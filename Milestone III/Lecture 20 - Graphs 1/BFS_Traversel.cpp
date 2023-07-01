#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }
    
    queue<int> q;
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
           q.push(i);
           while(!q.empty())
           {
               int temp=q.front();
               q.pop();
               vis[temp]=true;
               cout<<temp<<' ';
               for(int j=0;j<v;j++)
               {
                 if (graph[temp][j] && !vis[j]) {
                   q.push(j);
                   vis[j]=true;
                 }
               }
           }
        }
    }
    return 0;
}
