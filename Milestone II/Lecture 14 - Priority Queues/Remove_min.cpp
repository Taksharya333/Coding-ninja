#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }
    int removeMin() {
        // Write your code here
        if (isEmpty()) {
            return INT_MIN;
        }
        int ans= pq[0];
        int size=pq.size();
        pq[0]=pq[size-1];
        pq.pop_back();
        size--;
        int index=0;
        while(index<size )
        {
            int index1= 2*index+1;
            int index2 = 2*index+2;
            if(index2<size)
            {
                int mini = min(pq[index1],pq[index2]);
             if(pq[index]>mini)
             {
                 if(pq[index1]<=pq[index2])
                 {
                     swap(pq[index],pq[index1]);
                     index=index1;
                 }
                 else {
                       swap(pq[index],pq[index2]);
                     index=index2;
                 }
             }
             else return ans;
            }
            else if(index1<size){
               if (pq[index] > pq[index1]) {
                  swap(pq[index], pq[index1]);
                  index=index1;
                }
                else return ans;
            }
            else return ans;
        }
        return ans;
    }
};