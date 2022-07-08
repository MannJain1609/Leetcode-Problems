// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

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
#include<bits/stdc++.h>
void reorderList(Node* head) {
    // Your code here
    deque<Node*> q;
        Node* temp = head;
        while(temp)
        {
            Node* t = temp;
            temp = temp->next;
            t->next = NULL;
            q.push_back(t);
        }
        while(!q.empty())
        {
            Node* l1 = q.front();
            q.pop_front();
            Node* l2 = NULL;
            if(!q.empty())
            {
                l2 = q.back();
                q.pop_back();
            }
            if(temp == NULL)
            {
                temp = l1;
            }
            else
            {
                temp->next = l1;
                temp = temp->next;
            }
            if(l2)
            {
                temp->next = l2;
                temp = temp->next;
            }
        }
}