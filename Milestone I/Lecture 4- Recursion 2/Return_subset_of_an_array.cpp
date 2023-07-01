#include <iostream>
using namespace std;

void help(int input[], int n, int output[][20], int & i)
{
if(n==0)return;
int k=i;
output[i][0]=1;
output[i++][1]=input[n-1];
for (int j = 0; j < k; j++) {
  output[i][0] = output[j][0]+1;
  output[i][1] = input[n - 1];
  for (int l = 0; l < output[j][0]; l++) {
    output[i][l+2]=output[j][l+1];
   }
   i++;
}
help(input,n-1,output,i);
}
int subset(int input[], int n, int output[][20]) {
    // Write your code here
	int i=0;
	help(input,n,output,i);
return i;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
