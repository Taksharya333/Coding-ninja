#define mod 1000000007
int balancedBTs(int n) {
    // Write your code here
    if(n<2)return 1;
    int x  = balancedBTs(n-1);
    int y = balancedBTs(n-2);
    int temp1=  (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    int ans =  (int)((long)(temp1+temp2)%mod);
   return ans;
}