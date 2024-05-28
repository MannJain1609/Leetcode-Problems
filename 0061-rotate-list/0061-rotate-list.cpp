/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* help(ListNode* root, int k)
    {
        if(k == 0 || root->next == NULL)
            return root;
        
        ListNode* temp = root;
        ListNode* prev = NULL;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        temp->next = root;
        prev->next = NULL;
        root = temp;
        return help(root,k-1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        if(head == NULL)
            return NULL;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            temp = temp->next;
            n++;
        }
        return help(head, k%n);
    }
};