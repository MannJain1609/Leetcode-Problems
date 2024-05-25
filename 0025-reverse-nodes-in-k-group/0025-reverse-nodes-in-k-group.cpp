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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* ans = NULL;
        while(temp != NULL)
        {
            ListNode* t = temp->next;
            temp->next = ans;
            ans = temp;
            temp = t;
        }
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = NULL;
        ListNode* a = NULL;
        ListNode* temp = head;
        while(temp != NULL)
        {
            int count = 0;
            ListNode* h = temp;
            ListNode* prev = NULL;
            while(count < k && temp!=NULL) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if(count == k) {
                prev->next = NULL;
                ListNode* r = reverseList(h);
                if(ans == NULL) {
                    ans = r;
                    a = h;
                }
                else {
                    a->next = r;
                    a = h;
                }
            }
            else {
                a->next = h;

            }

        }
        return ans;
    }
};