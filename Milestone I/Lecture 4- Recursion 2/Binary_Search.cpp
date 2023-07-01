#include <iostream>
using namespace std;
// input - input array
// size - length of input array
// element - value to be searched
int help(int input[],int i,int j,int element)
{
    int mid=(i+j)/2;
    if(i>=j)return -1;
    if(element==input[i])return i;
    else if(element==input[j])return j;
    else if(element==input[mid])return mid;
    else if(element<input[mid]) return help(input,i,mid-1,element);
    else 
      return help(input, mid + 1, j,element);
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
if(element<input[0] || element>input[size-1])return -1;
return help(input,0,size-1,element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
