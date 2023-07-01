#include<iostream>
using namespace std;
bool checksequenece(char large[] , char*small) {
int i=0;
int j=0;
while(large[i]!='\0')
{
if(small[j]=='\0')return true;
if(large[i]==small[j])j++;
i++;
}
return false;
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
