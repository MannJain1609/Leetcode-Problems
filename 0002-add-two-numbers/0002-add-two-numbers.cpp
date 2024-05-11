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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int sum = carry;
            if(l1)
                sum+= l1->val;
            if(l2)
                sum+= l2->val;
            int val = sum%10;
            sum = sum/10;
            carry = sum%10;
            ListNode* n = new ListNode(val);
            if(ans == NULL)
            {
                ans = n;
                temp = ans;
            }
            else {
                temp->next = n;
                temp = temp->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry > 0)
        {
            ListNode* n = new ListNode(carry);
            if(ans == NULL)
                return n;
            else{
                temp->next = n;
            }
        }
        return ans;
    }
};