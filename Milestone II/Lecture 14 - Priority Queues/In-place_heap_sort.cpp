using namespace std;
void heapSort(int arr[], int n) {
    // Write your code
    if(n==1)return;
    for(int i=1;i<n;i++)
    {
        int size =i;
        while(size>0)
        {
            int parentIndex = (size-1)/2;
            if(arr[size]<arr[parentIndex])
            swap(arr[size],arr[parentIndex]);
            else break;
            size= parentIndex;
        }
    }
    for(int size=n-1;size>0;size--)
    {
        swap(arr[0],arr[size]);
        int index=0;
        int left=1;
        int right=2;
        while(left<size)
        {
            int mini= index;
            if(arr[index]>arr[left])
                mini=left;
             if(right<size && arr[mini]>arr[right])
             mini =right;
             if(mini==index)break;
             swap(arr[index],arr[mini]);
             index=mini;
             left=2*index +1;
             right =2* index+2;
        }
    }
}