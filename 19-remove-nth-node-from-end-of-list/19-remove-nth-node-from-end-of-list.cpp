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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int nodes = 0;
        while(temp)
        {
            temp = temp->next;
            nodes++;
        }
        int node = nodes - n;
        int count = 0;
        temp = head;
        ListNode* prev = NULL;
        while(count<node)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if(prev == NULL)
            head = head->next;
        else
        {
            prev->next = temp->next;
        }
        temp->next = NULL;
        delete(temp);
        return head;
    }
};