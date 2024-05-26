class FenwickTree {
    public: 
    vector<int>BIT;
    int n;

    FenwickTree(int n) {
        this->n = n;
        BIT.resize(n+1,0);
    }
    int query(int id) {
        int ans = 0;
        while(id > 0) {
             ans = max(ans,BIT[id]);
             id -= (id & -id);
        }
        return ans;
    }

    void add(int id, int val) {
        while(id <= n) {
            BIT[id] = max(val,BIT[id]);
            id += (id & -id);
        }
    }
};


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        //Fenwick Tree
        set<int>obs;
        int n = min(5 * 10000, 3 * (int)queries.size()) + 1;
        obs.insert(0);
        obs.insert(n);
        FenwickTree ft(n);
        for(auto q: queries) {
            if(q[0] == 1) {
                obs.insert(q[1]);
            }
        }
        //putting all the obstacles in the tree
        for(auto it = obs.begin(); it!=obs.end(); it++)
        {
            if(it == obs.begin())
                continue;
            auto prevIt = prev(it);
            int gapSize = (*it) - (*prevIt);
            ft.add((*it), gapSize);
        }

        //reversing and removing the obstacles
        vector<bool>ans;
        int size = queries.size();
        for(int i=size-1; i>=0; i--)
        {
            vector<int>& q = queries[i];
            //remove the obstacle
            if(q[0] == 1) {
                auto it = obs.find(q[1]);
                auto prevIt = prev(it);
                auto nextIt = next(it);
                int val = *nextIt - *prevIt;
                obs.erase(it);
                ft.add(*nextIt, val);
            }
            //check the block can be placed
            else {
                auto it = obs.upper_bound(q[1]);
                auto prevIt = prev(it);
                int gapSize = max(ft.query(*prevIt), q[1] - *prevIt);
                ans.push_back(gapSize >= q[2]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
        //Gives TLE
        // vector<bool>res;
        // set<int>obs;
        // int size = 0;
        // for(auto q: queries) {
        //     if(q[0] == 1) {
        //         obs.insert(q[1]);
        //         size++;
        //         continue;
        //     }
        //     int sz = q[2];
        //     if(size == 0) {
        //         if(sz > q[1])
        //             res.push_back(false);
        //         else
        //             res.push_back(true);
        //     }
        //     else {
        //         int prev = 0;
        //         bool flag = true;
        //         for(auto it = obs.begin(); it!=obs.end(); it++)
        //         {
        //             //cout<<*it<<endl;
        //             if(*it > q[1])
        //             {
        //                 break;
        //             }
        //             if(*it - prev >= sz) {
        //                 res.push_back(true);
        //                 flag = false;
        //                 prev = *it;
        //                 break;
        //             }
        //             else {
        //                 prev = *it;
        //             }
        //         }
        //         if(flag) {
        //             if(q[1] - prev >= sz) {
        //                 res.push_back(true);
        //             }
        //             else {
        //                 res.push_back(false);
        //             }
        //         }
        //     }
        // }
        // return res;
    }
};