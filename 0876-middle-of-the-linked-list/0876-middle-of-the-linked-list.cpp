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
    int size(ListNode* head)
    {
        if(head==NULL)
            return 0;
        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int size_ll = size(head);
        int upto = size_ll/2;
        int i=0;
        while(i<upto)
        {
            head=head->next;
            i++;
        }
        return head;
    }
};