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
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        ListNode* temp = head;
        while(temp)
        {
            ListNode* t = temp;
            temp = temp->next;
            t->next = NULL;
            q.push_back(t);
        }
        while(!q.empty())
        {
            ListNode* l1 = q.front();
            q.pop_front();
            ListNode* l2 = NULL;
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
};