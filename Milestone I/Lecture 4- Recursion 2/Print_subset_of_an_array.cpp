#include <iostream>
using namespace std;
void help(int input[], int n, int output[][20], int i) {
  if (n == 0)
    return;
  int k = i;
  output[i][0] = 1;
  output[i++][1] = input[n - 1];
  cout<<output[i-1][1]<<endl;
  for (int j = 0; j < k; j++) {
    output[i][0] = output[j][0] + 1;
    output[i][1] = input[n - 1];
    cout<<output[i][1]<<' ';
    for (int l = 0; l < output[j][0]; l++) {
      output[i][l + 2] = output[j][l + 1];
      cout<<output[j][l+1]<<' ';
    }
    i++;
    cout<<endl;
  }
  help(input, n - 1, output, i);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[100000][20];
    
    help(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
