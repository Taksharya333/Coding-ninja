#include <vector>
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
	int i, j, x, y; 
    int n=value;
	int m=numDenominations;
    int table[n + 1][m]; 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            x = (i-denominations[j] >= 0) ? table[i - denominations[j]][j] : 0; 
            y = (j >0) ? table[i][j - 1] : 0; 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
}