#include <bits/stdc++.h>
using namespace std;

int findminw( vector <int>&weights,vector <bool>& vis)
{
    int mini=INT_MAX;
    int ans=0;
    for(int i=0;i<weights.size();i++)
    {
        if(vis[i])continue;
        if(weights[i]<mini)
        {
            ans=i;
            mini=weights[i];
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
    vector <int>weights(v,INT_MAX);
    weights[0]=0;
    vector <int>parents(v,-1);
    int vertics=0;
    for(int i=0;i<v;i++)
    {
        vis[vertics]=true;
        for(int j=0;j<v;j++)
        {
            if(adj[vertics][j] && !vis[j])
            {
                weights[j]=min(weights[j],adj[vertics][j]);
                if(weights[j]==adj[vertics][j])
                parents[j]=vertics;
            }
        }
         vertics=findminw(weights,vis);
    }
    vector<vector<int>> output(v,vector<int>(v,0));
    for(int i=1;i<v;i++)
    {
        cout<<min(i,parents[i])<<' '<<max(i,parents[i])<<' '<<weights[i]<<endl;
    }
    return 0;
}