#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything
void help(char input[],int index,int gap)
{
    if(input[gap]=='\0')
    {
        input[index]='\0';
        return;
    }
  while(input[gap]=='x')
     gap++;
    input[index]=input[gap];
    help(input,index+1,gap+1);
}
void removeX(char input[]) {
    // Write your code here
    help(input,0,0);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
