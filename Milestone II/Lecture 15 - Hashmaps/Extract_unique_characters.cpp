#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
	unordered_map<char, bool> map;
	for(char i:str)
	map[i]=true;
	string ans="";
	for(char i: str)
	{
		if(map[i]==true)
		{
			map[i]=false;
			ans+=i;
		}
	}
	return ans;
}