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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head,*prev=NULL;
        bool start = true;
        while(temp && temp->next)
        {
            ListNode* t = temp->next;
            temp->next = t->next;
            t->next = temp;
            if(prev)
                prev->next = t;
            if(start)
            {
                start = false;
                head = t;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};