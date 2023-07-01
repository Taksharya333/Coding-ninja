#include <iostream>
#include <vector>
using namespace std;



int isTriangle(vector<vector<int>>&edges,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(edges[i][j]==1)
            {
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j)
                        continue;
                    if(edges[j][k]==1 && edges[k][i]==1)
                        count++;
                }
            }
        }
    }
    return count/6; 
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>output(v,vector<int>(v,0));
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        
        output[f][s] = 1;
        output[s][f] = 1;
    }
  
    int sum = 0;
   sum = sum + isTriangle(output,v);
    cout<<sum<<endl;
}