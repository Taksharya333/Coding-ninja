#include<bits/stdc++.h>
#include <string>
using namespace std;

  string h[] = {"",    "",    "abc",  "def", "ghi",
                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void help(int num, string s, int count) {

    int val = num / pow(10, count);
    val = val % 10;

    for (int j = 0; j < h[val].length(); j++) {
      if (count == 0)
        cout<< s + h[val][j]<<endl;
      help(num, s + h[val][j], count - 1);
    }
  }
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
      int count=0;
   int temp=num;
   while(temp!=0)
   {
       temp/=10;
       count++;
   }
    help(num,"",count-1);
    
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
