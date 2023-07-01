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
    vector<bool> vis(v,false);
    queue<int>q;
    vector<vector<int>>ans;
    for(int i=0;i<v;i++){
        if(!vis[i])
        {
            vector<int>* inter=new vector<int>();
            q.push(i);
    while(!q.empty())
    {
        int temp=q.front();
        inter->push_back(temp);
        q.pop();
         vis[temp]=true;
        for(int i=0;i<v;i++)
        {
            if(graph[temp][i])
            {
              if (!vis[i]) {
                  vis[i]=true;
                q.push(i);
              }
            }
        } 
    }
    sort(inter->begin(),inter->end());
    ans.push_back(*inter);
    delete inter;
        }
    }
    int size= ans.size();
    for(int i=0;i<size;i++)
    {
        int tt=ans[i].size();
        for(int j=0;j<tt;j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}