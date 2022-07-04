/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void bfs(Node* root) {
        if(root == NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node* temp = q.front();
                q.pop();
                if(i == size-1)
                    temp->next = NULL;
                else
                    temp->next = q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};