

int countMinStepsToOne(int n)
{
	//Write your code here
	if(n==1)return 0;
	int a= countMinStepsToOne(n-1);
	int b=INT_MAX,c=INT_MAX;
	if(n%3==0 && n>2)
	b=countMinStepsToOne(n/3);
	if(n%2==0)
	c=countMinStepsToOne(n/2);
	return 1+ min(a,min(b,c));
}