bool help(int * arr, int index, int n)
{
    if(index>=n)return true;
    int left = 2*index+1;
    int right=2*index +2;
   if(left>=n)return true;
   else {
       if(arr[index]<arr[left])return false;
       if(right>=n)return true;
       if(arr[index]<arr[right])return false;
       else return help(arr,left,n) && help(arr,right,n);
   }
}
bool isMaxHeap(int arr[], int n) {
    // Write your code here
    return help(arr,0,n);
}