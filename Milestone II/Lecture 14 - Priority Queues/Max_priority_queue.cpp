#include<bits/stdc++.h>
class PriorityQueue {
    // Declare the data members here
    vector<int> vec;
    int size;

   public:
    PriorityQueue() {
        // Implement the constructor here
        size=0;
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        vec.push_back(element);
        size++;
        int n=size-1;
        while(n>0)
        {
            int parent = (n-1)/2;
            if (vec[parent] < vec[n]) {
              swap(vec[n], vec[parent]);
              n=parent;
            }
            else break;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())return INT_MIN;
        return vec[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty())return INT_MIN;
        int ans=vec[0];
        vec[0]=vec[size-1];
        vec.pop_back();
        size--;
        int index=0;
        int left= 1;
        int right=2;
        while(left<size)
        {
            int maxi= index;
            if(vec[left]>vec[maxi])
            maxi=left;
            if(right<size && vec[right]>vec[maxi])
            maxi=right;
            if(maxi==index)break;
            swap(vec[maxi],vec[index]);
            index=maxi;
            left=2*index+1;
            right=2*index+2;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return size==0;
    }
};