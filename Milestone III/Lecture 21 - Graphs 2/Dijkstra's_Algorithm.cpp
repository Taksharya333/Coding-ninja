#include <bits/stdc++.h>
using namespace std;

int findminw( vector <int>&distances,vector <bool>& vis)
{
    int mini=INT_MAX;
    int ans=0;
    for(int i=0;i<distances.size();i++)
    {
        if(vis[i])continue;
        if(distances[i]<mini)
        {
            ans=i;
            mini=distances[i];
        }

    }
    return ans;
}
int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int f,s,t;
    vector<vector<int>> adj(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        cin>>f>>s>>t;
        adj[f][s]=t;
        adj[s][f]=t;
    }
    vector <bool> vis(v,false);
    vector <int>dis(v,INT_MAX);
    dis[0]=0;
    int vertics=0;
    for(int i=0;i<v;i++)
    {
        vis[vertics]=true;
        for(int j=0;j<v;j++)
        {
            if(adj[vertics][j] && !vis[j])
            {
                dis[j]=min(dis[j],adj[vertics][j]+dis[vertics]);
            }
        }
         vertics=findminw(dis,vis);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<' '<<dis[i]<<endl;
    }
    return 0;
}