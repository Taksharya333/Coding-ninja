#include<bits/stdc++.h>
using namespace std;
bool checkRedundantBrackets(string expression) {
	// Write your code here
	stack<char> st;
	int num=0;
	for(char c:expression)
	{
		if(c==')')
		{
			while(st.top()!='(')
			{
				st.pop();
				num++;
			}
			if(num<3)return true;
			st.pop();
			num=0;
		}
		else st.push(c);
	}
	return false;
}