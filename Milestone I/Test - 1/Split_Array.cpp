#include <iostream>
using namespace std;
bool help(int *input, int n, int start, int left, int right)
{
    if(start==n)
    return left==right;
    else if(input[start]%5==0)
    left+=input[start];
    else if(input[start]%3==0)
    right+=input[start];
    else return help(input,n,start+1,left + input[start],right)||help(input,n,start+1,left,right+input[start]);
    return help(input,n,start+1,left,right);
}
bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
return help(input,size,0,0,0);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
