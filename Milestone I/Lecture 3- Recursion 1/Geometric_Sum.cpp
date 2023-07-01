#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double two(int n)
{
  if (n == 0)
    return 1;
    else return two(n-1)/2;
}
double geometricSum(int k) {
    // Write your code here
   if(k==0)return 1;
   double x = two(k);
  return x + geometricSum(k - 1);
}
int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
