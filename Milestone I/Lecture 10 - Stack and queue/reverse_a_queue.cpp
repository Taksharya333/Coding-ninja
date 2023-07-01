#include<bits/stdc++.h>
using namespace std;
void reverseQueue(queue<int> &input) {
	// Write your code here
	if(input.size()<1)return;
	int help=input.front();
	input.pop();
	reverseQueue(input);
	input.push(help);
}