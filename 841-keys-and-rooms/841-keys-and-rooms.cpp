class Solution {
private:
    void bfs(vector<vector<int>>& rooms, vector<bool>& visited, int n) {
        queue<int> q;
        visited[0] = true;
        for(int key : rooms[0]) {
            q.push(key);
            visited[key] = true;
        }
        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            for(int key : rooms[room])
            {
                if(!visited[key]) {
                    q.push(key);
                    visited[key] = true;
                }
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        bfs(rooms,visited,n);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                return false;
        }
        return true;
    }
};