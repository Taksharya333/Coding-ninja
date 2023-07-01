#include <iostream>
using namespace std;

void merging(int input[],int start,int mid,int end)
{
  int *arr = new int[end - start + 1];
  int i = start, j = mid + 1, k = 0;
  while (i <= mid && j <= end) {
    if (input[i] < input[j])
      arr[k++] = input[i++];
    else
      arr[k++] = input[j++];
}
while(j<=end)arr[k++]=input[j++];
while(i<=mid)arr[k++]=input[i++];
k=0;
i = start;
 j = mid + 1; 
while (i <= mid) input[i++] = arr[k++];
while(j<=end)input[j++]=arr[k++];
delete []arr;
}
void merge(int input[],int i,int j)
{
	if(i==j)return;
	int mid = (i+j)/2;
	merge(input,i,mid);
	merge(input,mid+1,j);
	merging(input,i,mid,j);
}
void mergeSort(int input[], int size){
	// Write your code here
        merge(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}