#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string expression) 
{
    // Write your code here
    stack <char> st;
    for( auto i:expression)
    {
      if(i=='(')
      st.push(i);
      else{
          if(st.empty())return false;
          st.pop();
      }
    }
    if(st.empty())return true;
    else return false;
}