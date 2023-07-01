
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

bool isPalindrome(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL)return true;
	int len=0;
	Node * temp=head;
	while(head!=NULL)
	{
		len++;
		head=head->next;
	}
	int * arr= new int[len/2];
	head=temp;
	for(int i=0;i<len/2;i++)
	{
		arr[i]=head->data;
		head=head->next;
	}
	if(len%2==1)head=head->next;
	for(int i=(len/2)-1;i>=0;i--)
	{
		if(arr[i]!=head->data)return false;
		head=head->next;
	}
	return true;
}