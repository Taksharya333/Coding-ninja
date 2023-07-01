/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
     if(head==NULL)return NULL;
     int count=0;
     Node * ans= head;
    while(head->next!=NULL)
    {
        count+=head->data;
        count*=10;
        head=head->next;
    }
    if((count+head->data+1)%10==0)
    {
        Node *nhead=new Node(1);
        nhead->next=ans;
        while(ans!=NULL)
        {
            ans->data=0;
            ans=ans->next;
        }
        return nhead;
    }
    else 
    {
        head->data++;
        return ans;
    }
}


