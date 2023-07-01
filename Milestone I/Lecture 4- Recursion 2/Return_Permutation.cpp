#include <iostream>
#include <string>
using namespace std;

void help(string input, string output[], int& j,string s) {
  if (input.length() <= 1) {
   j=input.length();
    return;
  }
  if ( input.length()==2){
	  output[j++]=s+input[0]+input[1];
	  output[j++]=s+input[1]+input[0];
    return;
}
for (int i = 0; i < input.length(); i++) {
  help(input.substr(0, i) + input.substr(i + 1), output, j, s + input[i]);
}
}
int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	int j=0;
	help(input,output,j,"");
	return j;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
