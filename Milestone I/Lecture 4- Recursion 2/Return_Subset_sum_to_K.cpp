#include <iostream>
using namespace std;
void help(int input[],int startindex,int n, int k , int output[][50], int temp[], int & i, int j)
{
if ((k==0)||(k == 0 && startindex >= n)) {
  output[i][0] = j;
  for (int k = 0; k < j; k++) {
    output[i][k + 1] = temp[k];
  }
  i++;
  return;
}
if(startindex >= n)return; 
if (input[startindex] <= k) {
  temp[j] = input[startindex];
  help(input, startindex + 1, n, k - input[startindex], output, temp, i, j + 1);
}
help(input,startindex+1,n,k,output,temp,i,j);
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	int temp[1000];
	int i=0,j=0;
help(input,0,n,k,output,temp,i,j);
return i;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
