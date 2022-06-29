class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1])
            return a[0]>b[0];
        return a[1] < b[1];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(size, vector<int>(2,0));
        ans[0] = people[0];
        for(int i =1; i<size; i++)
        {
            int big = people[i][1];
            int start = 0;
            while(big>0 && start<i)
            {
                if(ans[start][0]>=people[i][0])
                    big--;
                start++;
            }
            //cout<<i<<" "<<start<<" ";
            int ind = i;
            while(ind!=start)
            {
                ans[ind] = ans[ind-1];
                ind--;
            }
            //cout<<ind<<endl;
            ans[ind] = people[i];
        }
        return ans;
    }
};