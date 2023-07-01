#include<bits/stdc++.h>
using namespace std;

void helper(int * arr, int index, int size, int val,int &ans)
{
  if (val == 0) {
    ans++;
  }
  if(index>=size)return;
  for(int i=index; i<size;i++)
  {
      if(arr[i]<=val)
      {
          helper(arr,i+1,size,val-arr[i],ans);
      }
  }
}
int main(){
    
    // write your code here
    int ans;
    int t;
    cin>>t;
    while (t--) {
        ans=0;
        int size, val;
        cin>>size>>val;
        int arr[size];
        int sum=0;
        for (int i = 0; i < size; i++) {
          cin >> arr[i];
            sum+=arr[i];
        }
      helper(arr,0,size,val,ans);
      cout << ans<<endl;
    }
    return 0;
}