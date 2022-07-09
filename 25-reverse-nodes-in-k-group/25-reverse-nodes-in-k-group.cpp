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
    ListNode* reverse_ll(ListNode* head, ListNode* r) {
        ListNode* temp = head;
        while(temp && temp->next)
        {
            ListNode* t = temp->next;
            temp->next = temp->next->next;
            t->next = head;
            head = t;
        }
        if(temp)
            temp->next = r;
        return head;
    }
    
    void print(ListNode* head) {
        ListNode* temp = head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp  = temp->next;
        }
        cout<<"NULL\n";
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == NULL)
            return head;
        ListNode* temp = head;
        int count = 1;
        while(temp)
        {
            temp = temp->next;
            if(temp)
                count++;
            if(count == k)
            {
                ListNode* r = NULL;
                if(temp) {
                    r = temp->next;
                    temp->next = NULL;
                }
                r = reverseKGroup(r,k);
                //print(r);
                temp = reverse_ll(head,r);
                break;
            }
        }
        if(temp)
            head = temp;
        return head;
    }
};