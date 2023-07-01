
int countStepsToOne(int n)
{
	//Write your code here
	int arr[n+1];
	arr[0]=0;
	arr[1]=0;
	for(int i=2;i<=n;i++)arr[i]=INT_MAX;
    for(int i=2;i<=n;i++)
    {	
		if(i%3==0 && i>2)
       arr[i]=min(arr[i],arr[i/3]);
	  if(i%2==0)
	   arr[i]=min(arr[i],arr[i/2]);
		arr[i]=min(arr[i],arr[i-1]);
		arr[i]++;
    }
	return arr[n];
}