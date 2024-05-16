class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        unordered_set<int>vis;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            if(dominoes[i] == 'L') {
                q.push({-1,i});
                vis.insert(i);
            }
            else if(dominoes[i] == 'R') {
                q.push({1,i});
                vis.insert(i);
            }
        }
        

        while(!q.empty())
        {
            int size = q.size();
            unordered_set<int>s;
            for(int i=0; i<size; i++)
            {
                auto [dir, ind] = q.front();
                q.pop();
                int new_ind = ind + dir;
                if(new_ind < 0 || new_ind >= n)
                    continue;
                if(s.find(new_ind) != s.end())
                {
                    dominoes[new_ind] = '.';
                }
                if(vis.find(new_ind) == vis.end())
                {
                    dominoes[new_ind] = (dir == -1) ? 'L' : 'R';
                    s.insert(new_ind);
                    vis.insert(new_ind);
                    q.push({dir, new_ind});
                }
            }
        }
        return dominoes;
    }
};

