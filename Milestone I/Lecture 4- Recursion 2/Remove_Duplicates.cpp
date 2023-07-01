#include <iostream>
using namespace std;

void remove(char * input,int index,int gap)
{
if(input[gap]=='\0'){
	input[index]='\0';
	return;
}
while(input[gap]==input[gap+1])gap++;
input[index]=input[gap];
remove(input,index+1,gap+1);
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	remove(input,0,0);

}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}