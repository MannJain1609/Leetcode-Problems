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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        while(list1!=NULL && list2!=NULL)
        {
            cout<<"vgj"<<endl;
            if(list1->val < list2->val) {
                if(ans == NULL) {
                    ans = list1;
                    temp = ans;
                }
                else {
                    temp->next = list1;
                    temp = temp->next;
                }
                list1 = list1->next;
            }
            else {
                if(ans == NULL) {
                    ans = list2;
                    temp = ans;
                }
                else {
                    temp->next = list2;
                    temp = temp->next;
                }
                list2 = list2->next;
            }
        }
        if(list1 == NULL)
        {
            if(ans == NULL) {
                    ans = list2;
                    temp = ans;
                }
            else
                temp->next = list2;
        }
        else {
            if(ans == NULL) {
                    ans = list1;
                    temp = ans;
                }
            else
                temp->next = list1;
        }
        return ans;
    }
};