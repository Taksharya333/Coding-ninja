#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int maximumProfit(int budget[], int n) {
    // Write your code here
sort(budget,budget+n);
int ans=0;
for(int i=n;i>=0;--i)
{
ans=max(ans,budget[i]*(n-i));
}
return ans;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
