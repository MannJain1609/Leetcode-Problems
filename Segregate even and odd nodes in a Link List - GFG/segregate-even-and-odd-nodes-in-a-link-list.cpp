// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        queue<Node*>q;
        Node* temp = head,*prev = NULL;
        while(temp)
        {
            if(temp->data & 1)
            {
                Node* add = temp;
                if(prev == NULL) {
                    head = temp->next;
                    temp = head;
                }
                else {
                    prev->next = temp->next;
                    temp = prev->next;
                }
                add->next = NULL;
                q.push(add);
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        while(!q.empty())
        {
            if(prev) {
                prev->next = q.front();
                prev = prev->next;
            }
            else
            {
                head = q.front();
                prev = head;
            }
            q.pop();
        }
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends