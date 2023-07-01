#include<iostream>
using namespace std;


int main(){

  // Write your code here
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i;j++)
    cout<<j+1;
    for(int j=0;j<2*i;j++)
    cout<<'*';
    for(int j=n-1-i;j>=0;j--)
    cout<<j+1;
    cout<<endl;
  }
  return 0;
}


