#include <iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

int converttoint(char input[],int size,int sizeref)
{
if(size<0)return 0;
return (input[size]-48)*pow(10,sizeref-size)+converttoint(input,size-1,sizeref);
}
int stringToNumber(char input[]) {
    // Write your code here
int stringsize=strlen(input);
return converttoint(input, stringsize - 1, stringsize - 1);
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
