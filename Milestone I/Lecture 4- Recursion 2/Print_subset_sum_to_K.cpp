#include <iostream>
using namespace std;
void help(int input[], int startindex, int n, int k,int temp[], int j) {
  if ((k == 0) || (k == 0 && startindex >= n)) {
    for (int k = 0; k < j; k++) {
      cout<< temp[k]<< ' ';
    }
    cout<<endl;
    return;
  }
  if (startindex >= n)
    return;
  if (input[startindex] <= k) {
    temp[j] = input[startindex];
    help(input, startindex + 1, n, k - input[startindex],temp,j + 1);
  }
  help(input, startindex + 1, n, k, temp, j);
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int temp[1000];
    help(input,0,size,k,temp,0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
