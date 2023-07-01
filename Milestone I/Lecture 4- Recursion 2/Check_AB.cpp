#include <iostream>
using namespace std;

bool check(char input[], int i) {
  if (input[i] == '\0')
    return true;
  if (i > 0) {
    if ((input[i] == 'b' && input[i+1] == 'b') && input[i-1]!='b') check(input,i+2);
    else if (input[i] == 'a') check(input,i+ 1);
	else return false;
  } 
  else if (input[i] == 'a')
    check(input, i + 1);
  else
    return false;
}
bool checkAB(char input[]) {
	// Write your code here
return check(input,0);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
