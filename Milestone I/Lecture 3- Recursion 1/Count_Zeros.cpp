#include <iostream>
using namespace std;
int help(int n)
{
     if(n==0) return 0;
     if(n%10==0)return 1 + help(n/10);
    else return help(n/10);
}
int countZeros(int n) {
    // Write your code here
   if(n==0)return 1;
   else return help(n);
}
int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
