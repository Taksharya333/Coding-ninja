#include <bits/stdc++.h>
int mc(int * dims, int i, int j, vector<vector<int>>& lookup)
{
    if (j <= i + 1) {
        return 0;
    }
    int min = INT_MAX;
    if (lookup[i][j] == 0)
    {
        for (int k = i + 1; k <= j - 1; k++)
        {
            int cost = mc(dims, i, k, lookup);
            cost += mc(dims, k, j, lookup);
            cost +=    dims[i] * dims[k] * dims[j];
            if (cost < min) {
                min = cost;
            }
        }
        lookup[i][j] = min;
    }
    return lookup[i][j];
}
int matrixChainMultiplication(int* arr, int n) {
  vector<vector<int>> lookup(n + 1, vector<int>(n + 1));
    return mc(arr, 0, n, lookup);
}