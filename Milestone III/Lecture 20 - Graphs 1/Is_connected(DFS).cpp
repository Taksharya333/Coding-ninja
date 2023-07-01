#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& graph, int start, vector<bool>& vis)
{
    if(vis[start])return;
     vis[start]=true;
   
    int size= graph[start].size();
    for(int i=0;i<size;i++)
    {
        dfs(graph,graph[start][i],vis);
    }
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
    int ans =0;
    for (int i = 0; i < v; i++) {
      if (!vis[i]) {
        dfs(graph, i, vis);
        ans++;
      }
    }
     if(ans<=1)
     cout<<"true";
     else cout<<"false";
     return 0;
}