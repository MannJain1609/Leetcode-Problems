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
    ListNode* reverse_ll(ListNode* head)
    {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        while(temp && temp->next)
        {
            ListNode* t = temp->next;
            temp->next = temp->next->next;
            t->next = head;
            head = t;
        }
        return head;
    }
    
    void print(ListNode* head)
    {
        ListNode* temp = head;
        while(temp) {
            cout<<temp->val<<"-> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* before_left = head;
        while(count<left-1) {
            before_left = before_left->next;
            count++;
        }
        ListNode* l = before_left->next;
        if(left == 1)
            l = before_left;
        ListNode* before_right = l;
        count = left;
        while(count<right) {
            before_right = before_right->next;
            count++;
        }
        
        ListNode* r = before_right->next;
        
        if(before_left == l)
            before_left = NULL;
        else
            before_left->next = NULL;
        
        before_right->next = NULL;
        
        l = reverse_ll(l);
        
        if(before_left)
            before_left->next = l;
        else
            head = l;
        
        before_right = l;
        while(before_right && before_right->next) {
            before_right = before_right->next;
        }
        if(before_right)
            before_right->next = r;
        
        return head;
    }
};