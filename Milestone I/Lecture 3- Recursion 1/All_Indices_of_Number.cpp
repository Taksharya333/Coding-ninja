#include<iostream>
using namespace std;

void finIndex(int input[],int itrin,int size,int x, int output[],int &k)
{
  if(itrin==size)return;
  if(input[itrin]==x)
  {
    output[k]=itrin;
    k++;
  }
  finIndex(input,++itrin,size,x,output,k);
}
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
  int k=0;
finIndex(input,0,size,x,output,k);
return k;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


