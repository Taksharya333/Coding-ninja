#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> map1,map2;
    for (int i = 0; i < n; i++) {
      map1[arr1[i]]++;
      map2[arr1[i]]++;
    }
        for(int i=0;i<m;i++)
     map1[arr2[i]]++;
        for (pair<int, int> i : map1) {
            int temper =0;
            if(i.second>map2[i.first])
             temper=min(i.second-map2[i.first], map2[i.first]);
            if (temper > 0) {
              for (int j = 0; j < temper; j++)
                cout << i.first << endl;
            }
        }
}