/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void levelOrder(vector<vector<int>>& ans, Node* root) {
        if(root == NULL)
            return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node* temp = q.front();
                q.pop();
                a.push_back(temp->val);
                for(Node* N : temp->children)
                    q.push(N);
            }
            ans.push_back(a);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        levelOrder(ans,root);
        return ans;
    }
};