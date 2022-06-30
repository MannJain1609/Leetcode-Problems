class Solution {
private:
    int bfs(vector<string>& deadends, string target, string s) {
        unordered_set<string>dead(deadends.begin(), deadends.end());
        unordered_set<string>visited;
        //if "0000" is already a deadend, not possible
        if(dead.count(s) != 0)
            return -1;
        queue<string>q;
        q.push(s);
        visited.insert(s);
        int moves = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                string s = q.front();
                q.pop();
                if(s == target)
                    return moves;
                for(int k=0; k<4; k++)
                {
                    char temp = s[k];
                    //up
                    s[k] = temp == '9' ? '0':temp+1;
                    if(visited.count(s)==0 && dead.count(s)==0) {
                        q.push(s);
                        visited.insert(s);
                    }
                    s[k] = temp;
                    
                    //down
                    s[k] = temp =='0' ? '9': temp-1;
                    if(visited.count(s)==0 && dead.count(s)==0) {
                        q.push(s);
                        visited.insert(s);
                    }
                    s[k] = temp;
                }
            }
            moves++;
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends, target, "0000");
    }
};