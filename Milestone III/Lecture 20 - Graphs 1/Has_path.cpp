#include <bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>& graph, int start, int end, vector<bool>& vis)
{
    if(start==end)return true;
    if(vis[start])return false;
     vis[start]=true;
    bool ans=false;
    int size= graph[start].size();
    for(int i=0;i<size;i++)
    {
        ans=ans||dfs(graph,graph[start][i], end,vis);
        if(ans)return true;
    }
    return false;
}
int main() {
    // Write your code here
     int v,e;
    cin>>v>>e;
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
    vector<bool> vis(v,false);
     if(dfs(graph,start, end,vis))
     cout<<"true";
     else cout<<"false";
     return 0;
}