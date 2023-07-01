#include <bits/stdc++.h>
using namespace std;


vector<int>* dfs(vector<vector<int>>& graph, int start, int end, vector<bool>& vis)
{
    if(start==end){
        vector<int>*r=new vector<int>();
        r->push_back(end);
        return r;
    }
    if(vis[start])return NULL;
     vis[start]=true;
     vector<int>* temp;
    int size= graph[start].size();
    for(int i=0;i<size;i++)
    {
        if(graph[start][i])
        {temp=dfs(graph,i, end,vis);
          if (temp != NULL) {
            temp->push_back(start);
            return temp;
          }
        }
    }
    return NULL;
}
int main() {
    // Write your code here
     int v,e;
    cin>>v>>e;
    if(v==0||e==0)return 0;
    vector<vector<int>> graph(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }
    int start, end;
    cin>>start>>end;
    if(start>=v||end>=v)return 0;
    vector<bool> vis(v,false);
     vector<int> *ans=dfs(graph,start, end,vis);
     if(ans==NULL)return 0;
    for(int i:*ans)
    cout<<i<<' ';
     return 0;
}