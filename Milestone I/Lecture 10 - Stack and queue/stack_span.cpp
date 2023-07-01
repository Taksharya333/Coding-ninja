int* stockSpan(int *price, int size)  {
	// Write your code here
	if(size==1){
		price[0]=1;
		return price;
	}
	int * ans = new int[size];
	int index;
	int large=price[0];
	int prev = price[0];
	ans[0]=1;
	int remark;
	for(int i=1;i<size;i++)
	{
		if(price[i]<=prev)
			ans[i]=1;
			else{
				if(price[i]>large)
				{
					ans[i]=i+1;
					large=price[i];
					index=i;
				}
				else{
					remark=i-1;
					while(price[remark]<price[i])
					remark--;
					ans[i]=i-remark;
				}
			}
			prev=price[i];
	}
	return ans;
}
#include <stack>
int *stockSpan(int *price, int n)
{
stack<int> stk;
int *output = new int[n];
stk.push(0);
output[0] = 1;
for (int i = 1; i < n; ++i)
{
while (!stk.empty() && price[stk.top()] < price[i])
{
stk.pop();
}
if (stk.empty())
{
output[i] = i + 1;
}
else
{
output[i] = i - stk.top();
}
stk.push(i);
}
return output;
}