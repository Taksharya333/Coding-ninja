
int minCount(int n)
{
	//Write your code here
	int *arr=new int[n+1];
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=n;i++)
	arr[i]=INT_MAX;
    for(int i=2;i<=n;i++)
    {	
		int temp= sqrt(float(i));
		while(temp)
		{
			arr[i]=min(arr[i],arr[i-temp*temp]);
			temp--;
		}
		arr[i]++;
    }
	return arr[n];
}
