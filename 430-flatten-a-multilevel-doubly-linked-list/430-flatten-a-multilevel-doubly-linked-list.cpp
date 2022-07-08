/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head,*PREV = NULL;
        stack<Node*>s;
        while(temp || !s.empty())
        {
            if(temp == NULL)
            {
                Node* NEXT = s.top();
                s.pop();
                PREV->next = NEXT;
                NEXT->prev= PREV;
                temp = PREV;
            }
            else if(temp->child)
            {
                if(temp->next)
                    temp->next->prev = NULL;
                Node* NEXT = temp->next;
                Node* child = temp->child;
                temp->child = NULL;
                temp->next = child;
                child->prev = temp;
                if(NEXT)
                    s.push(NEXT);
            }
            PREV = temp;
            temp = temp->next;
        }
        return head;
    }
};