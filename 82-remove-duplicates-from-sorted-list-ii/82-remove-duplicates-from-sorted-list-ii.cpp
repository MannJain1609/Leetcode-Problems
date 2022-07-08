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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* temp =ans;
        deque<int>q;
        int prev = -101;
        while(head)
        {
            if(!q.empty() && head->val == q.back())
                q.pop_back();
            else if(head->val!=prev)
                q.push_back(head->val);
            prev = head->val;
            head = head->next;
        }
        while(!q.empty())
        {
            temp->next = new ListNode(q.front());
            q.pop_front();
            temp = temp->next;
        }
        return ans->next;
    }
};