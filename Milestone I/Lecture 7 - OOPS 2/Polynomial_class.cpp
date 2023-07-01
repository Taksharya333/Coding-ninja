/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include<bits/stdc++.h>
using namespace std;
class Polynomial {
     public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
   
    Polynomial(){
        capacity=10;
        degCoeff=new int[10];
        for(int i=0;i<capacity;i++)
        degCoeff[i]=0;
    }
    Polynomial(Polynomial const & a){
        capacity= a.capacity;
        degCoeff=new int[capacity];
        for(int i=0;i<capacity;i++)
        degCoeff[i]=a.degCoeff[i];
    }
    void setCoefficient(int pos,int val)
    {
        if(pos<capacity)
        degCoeff[pos]=val;
        else{
            int *temp=degCoeff;
            degCoeff=new int[pos+1];
            for(int i=0;i<capacity;i++)
            degCoeff[i]=temp[i];
            for(int i=capacity;i<pos;i++)
                degCoeff[i]=0;
            delete [] temp;
            capacity=pos+1;
            degCoeff[pos]=val;
            }
        }
        Polynomial operator+(Polynomial const &p2){
         Polynomial p3;
         p3.setCoefficient(max(capacity,p2.capacity), 0);
         int i;
         for(i=0;i<min(capacity,p2.capacity);i++)
         p3.setCoefficient(i, degCoeff[i]+p2.degCoeff[i]);
         while (i < capacity) {
           p3.setCoefficient(i, degCoeff[i]);
           i++;
         }
         while(i<p2.capacity){
              p3.setCoefficient(i, p2.degCoeff[i]);
             i++;}
             return p3;
        }
       Polynomial operator-(Polynomial const &p2){
        Polynomial p3;
         p3.setCoefficient(max(capacity,p2.capacity), 0);
         int i;
         for(i=0;i<min(capacity,p2.capacity);i++)
         p3.setCoefficient(i, degCoeff[i]-p2.degCoeff[i]);
         while (i < capacity) {
           p3.setCoefficient(i, degCoeff[i]);
           i++;
         }
         while(i<p2.capacity){
              p3.setCoefficient(i, p2.degCoeff[i]*(-1));
             i++;}
             return p3;
        }
        void operator=(Polynomial &p2){
            capacity=p2.capacity;
            degCoeff=new int[capacity];
            for(int i=0;i<capacity;i++)
            degCoeff[i]=p2.degCoeff[i];
        }
        Polynomial operator*(Polynomial const &p2){
            Polynomial p3;
            p3.setCoefficient(capacity+p2.capacity,0);
            for(int i=0;i<capacity;i++)
                for(int j=0;j<p2.capacity;j++)
                    p3.degCoeff[i+j]+= degCoeff[i]*p2.degCoeff[j];
            return p3;
        }
        void print()
        {
            for(int i=0;i<capacity;i++)
                if(degCoeff[i]!=0)
                        cout<<degCoeff[i]<<"x"<<i<<' ';
            cout<<endl;
        }
};



//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
