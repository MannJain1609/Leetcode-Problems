// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  private:
    Node* mergedlist(Node* l1, Node*l2) {
        Node* merged = new Node(0);
        Node* temp = merged;
        while(l1 && l2)
        {
            if(l1->data<l2->data)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1)
        {
            temp->next = l1;
        }
        else if(l2)
        {
           temp->next = l2;
        }
        return merged->next;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL)
                return head;
            Node* slow = head;
            Node* fast = head;
            Node* temp = slow;
            while(fast!=NULL && fast->next!=NULL)
            {
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = NULL;
            Node* l1 = mergeSort(head);
            Node* l2 = mergeSort(slow);
            return mergedlist(l1,l2);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends