#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
     int v,e;
    cin>>v>>e;
    if(v==0||e==0)return 0;
    vector<vector<int>> graph(v);
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f].push_back(s);
        graph[s].push_back(f);
    }
    int start, end;
    cin>>start>>end;
    if(start>=v||end>=v)return 0;
    vector<bool> vis(v,false);
    unordered_map<int,int>map;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int temp=q.front();
        if(temp==end)break;
        q.pop();
         vis[temp]=true;
        int size = graph[temp].size();
        for(int i=0;i<size;i++)
        {
          if (!vis[graph[temp][i]]) {
            map[graph[temp][i]] = temp;
            if (graph[temp][i] == end)
              break;
            q.push(graph[temp][i]);
          }
        }
        if(map.find(end)!=map.end())break;
    }
   if(q.empty())return 0;
    cout<<end<<' ';
    while(end!=start)
    {
        cout<<map[end]<<' ';
        end=map[end];
    }
    return 0;
}