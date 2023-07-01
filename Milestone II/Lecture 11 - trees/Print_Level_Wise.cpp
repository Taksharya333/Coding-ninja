#include<bits/stdc++.h>
using namespace std;
/************************************************************
 
    Following is the structure for the TreeNode class


    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
************************************************************/

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
   queue<TreeNode<int> *> q;
   q.push(root);
   while(!q.empty())
   {    root=q.front();
         q.pop();
        cout<<root->data<<':';
        int size=root->children.size();
        for (int i = 0; i < size; i++) {
          cout << root->children[i]->data;
          if (i != size - 1)
            cout << ',';
            q.push( root->children[i]);
        }
        cout << endl;
   }
}