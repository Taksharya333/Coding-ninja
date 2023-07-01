#include<bits/stdc++.h>
using namespace std;
int findUnique(int *arr, int n) {
    // Write your code here
    if(n==1)return arr[0];
    sort(arr,arr+n);
    int temp=arr[0];
    for(int i=1;i<n-1;i++)
    { 
        if(temp!=arr[i])return temp;
        else{
            i++;
            temp=arr[i];
        }
    }
    return temp;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}