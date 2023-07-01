#include <iostream>
#include <string.h>
using namespace std;

void help(string input, int n, string s) {

  if (n == input.length()) {
    cout<< s<<endl;
    return;
  }
  char t = input[n] + 48;
  help(input, n + 1, s + t);

  if (n < input.length() - 1) {
    string temp = "";
    temp += input[n];
    temp += input[n + 1];
    int tt = stoi(temp);
    if (tt < 27) {
      t = tt + 96;
      help(input, n + 2, s + t);
    }
  }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    help(input,0,"");
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
