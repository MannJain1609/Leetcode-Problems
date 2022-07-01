/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copyList = NULL;
        
        Node* temp = head;
        unordered_map<Node*,int>mp;
        unordered_map<int,Node*>copy_mp;
        int index = 0;
        while(temp)
        {
            mp.insert({temp,index});
            index++;
            temp = temp->next;
        }
        
        temp = head;
        Node* copy_temp = NULL;
        queue<Node*>q;
        index = 0;
        while(temp)
        {
            if(copyList == NULL)
            {
                copyList = new Node(head->val);
                copy_temp = copyList;
                q.push(temp->random);
                copy_mp.insert({index,copy_temp});
                index++;
                temp = temp->next;
                continue;
            }
            copy_temp->next = new Node(temp->val);
            copy_temp = copy_temp->next;
            q.push(temp->random);
            copy_mp.insert({index,copy_temp});
            index++;
            temp = temp->next;
        }
        copy_temp = copyList;
        while(!q.empty())
        {
            Node* t = q.front();
            q.pop();
            if(t == NULL)
            {
                copy_temp = copy_temp->next;
                continue;
            }
            copy_temp->random = copy_mp[mp[t]];
            copy_temp = copy_temp->next;
        }
        return copyList;
    }
};