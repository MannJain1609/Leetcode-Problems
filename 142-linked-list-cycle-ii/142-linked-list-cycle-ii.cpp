/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle)
            return NULL;
        ListNode* cycleNode = head;
        while(cycleNode!=slow)
        {
            cycleNode = cycleNode->next;
            slow = slow->next;
        }
        return cycleNode;
    }
};