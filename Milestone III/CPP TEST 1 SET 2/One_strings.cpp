int findOneStrings(string &str) 
{
	// Write your code here.
	int n=str.length();
	int ans=0;
	int sum=0;
	for(int i=1;i<n+1;i++)
	{
		if(str[i-1]=='1')
		{
			sum++;
		}
		else{
			if(sum>0)
			ans+=(sum*(sum+1))/2;
			sum=0;
		}
	}
	ans+=(sum*(sum+1))/2;
	return ans;
}