
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	if(n==0||m==0)return 0;
   for (int i=0;i<n;i++) 
    for (int j=0;j<m;j++) 
       arr[i][j]=!arr[i][j]; 
    int max=0;
    for (int i=1;i<n;i++)
    {  for (int j=1;j<m;j++)
         {    if (!arr[i][j]) continue;
             arr[i][j]=min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
              if (max<arr[i][j]) max=arr[i][j];
         }
      
    }
    
   return max; 
}