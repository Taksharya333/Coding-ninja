#include<bits/stdc++.h>
int countBracketReversals(string input) {
	// Write your code here
	int ans=0;
	int st=0;
        for (char i : input) {
          if (st==0 && i == '}') {
            ans++;
            st++;
          } else if (i == '}')
		   st--;
		   else st++;
        }
		if(st%2==1)return -1;
		ans+=st/2;
        return ans;
}