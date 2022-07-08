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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*>q;
        ListNode* temp = head,*prev = NULL;
        while(temp)
        {
            if(temp->val >= x)
            {
                ListNode* add = temp;
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