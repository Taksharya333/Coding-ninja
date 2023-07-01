#include <iostream>
#include <string>
using namespace std;

void help(string input, int n, string output[10000], string s, int &i) {
  
 if(n==input.length())
 {
     output[i++]=s;
     return;
 }
 char t=input[n]+48;
 help(input,n+1,output,s+t,i);
 
   if ( n < input.length() - 1) {
     string temp = "";
     temp += input[n];
     temp += input[n + 1];
     int tt = stoi(temp);
     if (tt < 27) {
       t = tt + 96;
       help(input, n + 2, output, s + t, i);
     }
   }
 
}
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    int i=0;
    help(input,0,output,"",i);
return i;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
