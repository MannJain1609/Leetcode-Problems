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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        stack<int> s;
        while(fast && fast->next)
        {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == head)
            return true;
        //odd nodes case
        if(fast!=NULL)
            slow = slow->next;
        while(slow)
        {
            if(slow->val != s.top())
                return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};