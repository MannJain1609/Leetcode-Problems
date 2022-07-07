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
private:
    ListNode* sum(ListNode* l1, ListNode* l2) {
        int carry = 0,add = 0;
        ListNode* head = NULL, *temp = head;
        while(l1 && l2)
        {
            add = l1->val + l2->val + carry;
            ListNode* ins = new ListNode(add%10);
            carry = add/10;
            if(head == NULL)
            {
                head = ins;
                temp = head;
            }
            else
            {
                temp->next = ins;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            add = l1->val + carry;
            ListNode* ins = new ListNode(add%10);
            carry = add/10;
            if(head == NULL) 
            {
                head = ins;
                temp = head;
            }
            else
            {
                temp->next = ins;
                temp = temp->next;
            }
            l1 = l1->next;
        }
        while(l2)
        {
            add = l2->val + carry;
            ListNode* ins = new ListNode(add%10);
            carry = add/10;
            if(head == NULL) 
            {
                head = ins;
                temp = head;
            }
            else
            {
                temp->next = ins;
                temp = temp->next;
            }
            l2 = l2->next;
        }
        if(carry)
            temp->next = new ListNode(carry);
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return sum(l1,l2);
    }
};