#include <iostream>
using namespace std;
#include<bits/stdc++.h>
bool check(char input[],int st,int size)
{
if(input[st]!=input[size])return false;
else if(size<=st)return true;
return check(input,st+1,size-1);
}
bool checkPalindrome(char input[]) {
    // Write your code here
int n = strlen(input);
return check(input,0,n-1);
}



int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
