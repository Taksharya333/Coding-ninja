#include <iostream>
#include <string>
using namespace std;

void help(string input, string s) {
  if(input.length()==0)return;
  else if (input.length() == 1) {
   cout<<input;
    return;
  } else if (input.length() == 2) {
    cout<< s + input[0] + input[1]<<endl;
	cout<< s + input[1] + input[0]<<endl;
    return;
  }
  for (int i = 0; i < input.length(); i++)
    help(input.substr(0, i) + input.substr(i + 1), s + input[i]);
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	help(input,"");
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}