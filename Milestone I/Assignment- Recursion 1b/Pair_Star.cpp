#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.
#include<bits/stdc++.h>
using namespace std;
void star(char input[],string *s)
{
if(input[0]=='\0')return;
if (input[0] == input[1]) {
*s += input[0];
*s+="*";
}
else *s+=input[0];
star(input+1,s);
}
void pairStar(char input[]) {
    // Write your code here
string s;
star(input,&s);
int i;
for(i =0;i<s.length();i++)
input[i]=s[i];
input[i]='\0';
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
