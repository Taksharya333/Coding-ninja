#define mod 1000000007
int balancedBTs(int n) {
    // Write your code here
   int *arr= new int[n+1];
   for(int i=0;i<=n;i++)arr[i]=-1;
   arr[0]=1;
   arr[1]=1;
   for(int i=2;i<n+1;i++)
   {
      int x  =arr[i-1];
      int y  =arr[i-2];
    int temp1=  (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
   arr[i] =  (int)((long)(temp1+temp2)%mod);
   }
   return arr[n];
}