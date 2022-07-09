// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method
void print(Node* root) {
    Node* temp = root;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

Node* reverse_ll(Node* root) {
    Node* temp = root;
    while(temp && temp->next)
    {
        Node* t = temp->next;
        temp->next = temp->next->next;
        t->next = root;
        root = t;
    }
    return root;
}
Node* sub(Node* l1, Node* l2) 
{
    l1 = reverse_ll(l1);
    l2 = reverse_ll(l2);
    Node* ans = new Node(0),*temp = ans;
    int carry = 0;
    while(l1 && l2)
    {
        int d = l1->data - l2->data + carry;
        if(d<0)
        {
            carry = -1;
            d+=10;
        }
        else
            carry = 0;
        Node* ins = new Node(d);
        temp->next = ins;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1)
    {
        int d = l1->data+carry;
        if(d<0)
        {
            carry = -1;
            d+=10;
        }
        else
            carry = 0;
        Node* ins = new Node(d);
        temp->next = ins;
        temp = temp->next;
        l1 = l1->next;
    }
    while(l2)
    {
        int d = l2->data+carry;
        if(d<0)
        {
            carry = -1;
            d+=10;
        }
        else
            carry = 0;
        Node* ins = new Node(d);
        temp->next = ins;
        temp = temp->next;
        l2 = l2->next;
    }
    ans = ans->next;
    ans = reverse_ll(ans);
    while(ans)
    {
        if(ans->data == 0)
            ans = ans->next;
        else
            break;
    }
    return ans;
}
Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    while(l1)
    {
        if(l1->data == 0)
            l1 = l1->next;
        else
            break;
    }
    while(l2)
    {
        if(l2->data == 0)
            l2 = l2->next;
        else
            break;
    }
    Node* t1 = l1, *t2 = l2;
    while(t1 && t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    if(t1==NULL && t2 == NULL)
    {
        t1 = l1;
        t2 = l2;
        while(t1 && t2)
        {
            if(t1->data == t2->data)
            {
                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->data > t2->data)
                return sub(l1,l2);
            else
                return sub(l2,l1);
        }
        return new Node(0);
    }
    else if(t1 == NULL)
        return sub(l2,l1);
    return sub(l1,l2);
}