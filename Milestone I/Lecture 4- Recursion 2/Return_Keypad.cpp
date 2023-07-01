#include<bits/stdc++.h>
#include <string>
using namespace std;

  string h[] = {"",    "",    "abc",  "def", "ghi",
                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void help(int num, string output[], string s, int count, int &i) {

    int val = num / pow(10, count);
    val = val % 10;

    for (int j = 0; j < h[val].length(); j++) {
      if (count == 0)
        output[i++] = s + h[val][j];
      help(num, output, s + h[val][j], count - 1, i);
    }
  }
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
   int count=0;
   int temp=num;
   while(temp!=0)
   {
       temp/=10;
       count++;
   }
   int i=0;
    help(num,output,"",count-1,i);
    
    return i;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
