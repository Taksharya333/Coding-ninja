#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything
#include<bits/stdc++.h>
using namespace std;
void replacePi2(char input[], string* s)
{
  if (input[0] == '\0') return;
if(input[0]=='p'&&input[1]=='i')
{
	*s+="3.14";
	replacePi2(input+2,s);
} else {
	*s+=input[0];
  replacePi2(input + 1, s);
}
}
void replacePi(char input[]) {
	// Write your code here
	string s;
replacePi2(input,&s);
int i;
for(i=0;i<s.length();i++)
{
	input[i]=s[i];
}
input[i]='\0';
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
