/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/


class Deque {
    // Complete this class
    int * arr;
     int size;
     int index;
     public:
     Deque(){}
     Deque(int s)
     {
         arr = new int[10];
         size=10;
         index=0;
     }
    void insertFront(int element)
    {
        if(index==size){
            cout<<"-1"<<endl;
            return;
        }
        else if(index==0)
            arr[index++]=element;
        else{
            for(int i=index;i>0;i--)
                arr[i]=arr[i-1];
                arr[0]=element;
                index++;
        }
    }
    void insertRear(int element)
    {
        if(index==size){
            cout<<"-1"<<endl;
            return;
        }
        else
            arr[index++]=element;
    }
    void deleteFront()
    {
        if(index==0)
        {
            cout<<"-1"<<endl;
            return;
        }
        else{
            for(int i=0;i<index-1;i++)
            arr[i]=arr[i+1];
            index--;
        }
    }
    void deleteRear()
    {
         if(index==0)
        {
            cout<<"-1"<<endl;
            return;
        }
        else  index--;
    }
    int getFront()
    {
           if(index==0)
        return -1;
        else return arr[0];
    }
    int getRear()
    {
          if(index==0)
            return -1;
        else return arr[index-1];
    }
};
