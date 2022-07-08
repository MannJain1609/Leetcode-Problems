// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
     Node* prev = head, *curr = head->next,*next = NULL;
     if(head->next)
        next = head->next->next;
     while(curr)
     {
         if(prev->data > curr->data)
         {
             int temp = curr->data;
             curr->data = prev->data;
             prev->data = temp;
         }
         if(next && next->data > curr->data)
         {
             int temp = curr->data;
             curr->data = next->data;
             next->data = temp;
         }
         prev = next;
         if(prev)
            curr = prev->next;
        else
            curr = NULL;
        if(curr)
            next = curr->next;
        else 
            next = NULL;
     }
     return head;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends