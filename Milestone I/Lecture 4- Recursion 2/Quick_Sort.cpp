#include<bits/stdc++.h>
using namespace std;
void quickSort(int input[], int start, int end)
	{
		if(start>=end)return;
    	int i=start+1,j=end;
		do
		{
			while(input[i]<input[start])i++;
			while(input[start]<input[j])j--;

			if(i < j)
			swap(input[i],input[j]);
		}while(i<j);
		swap(input[start],input[j]);
		quickSort(input,start,j-1);
		quickSort(input,j+1,end);
	}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
quickSort(input,0,size-1);
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

