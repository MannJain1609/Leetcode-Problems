class Solution {
public:
    void make_prefix(vector<int>& left, vector<int>& right, string& s, string& t, int n, int m)
    {
        int j=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == t[j])
            {
                left[j] = i;
                j++;
            }
            if(j == m)
                break;
        }

        j = m-1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == t[j])
            {
                right[j] = i;
                j--;
            }
            if(j == -1)
                break;
        }
    }

    bool check(vector<int>& left, vector<int>& right, int mid, int m)
    {
        //removes all element
        if(mid == m)
            return true;
        //if first mid elements or last mid elements can be removed
        if(right[mid] != -1 || left[m-mid-1] != -1)
            return true;
        //sliding winsdow of mid length to check if substring of mid length can be removed to get desired t
        int i=0, j= mid+1;
        while(j<m)
        {
            if(left[i] != -1 && right[j] != -1 && left[i] < right[j])
                return true;
            i++;
            j++;
        }
        return false;
    }
    int minimumScore(string s, string t) {
        //find minimum len of substring to be removed in t to make it a subsequence of s
        int n = s.size();
        int m = t.size();
        //left[i] stores the min length of prefix of s that will be used to get t[0:i] as subsequence
        //right[i] stores the min length of suffix of s that will be used to get t[i:] as subsequence
        vector<int>left(m,-1); 
        vector<int>right(m,-1);
        make_prefix(left,right,s,t,n,m);
        //binary search to find if mid len of substring is removed, then t will be a subsequence of s or not
        int low = 0, high = m;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(check(left,right,mid,m))
            {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
        // int n = s.size();
        // int m = t.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MAX));
        // for(int i=0; i<=n; i++)
        // {
        //     dp[i][0] = 0;
        // }
        // for(int j=0; j<=m; j++)
        // {
        //     dp[0][j] = j;
        // }
        // int min_index = m, max_index = 0;
        // for(int i=1; i<=n; i++)
        // {
        //     for(int j=1; j<=m; j++)
        //     {
        //         dp[i][j] = min(dp[i][j], min(1 + dp[i][j-1],dp[i-1][j]));
        //         if(s[i-1] == t[j-1])
        //         {
        //                 dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        //         }
        //     }
        // }
        // int num_del = 0, min_ind = m-1, max_ind = 0;
        // for(int i=1; i<=m; i++)
        // {
        //     if(dp[n][i] > num_del) {
        //         num_del = dp[n][i];
        //         max_ind = i-1;
        //         min_ind = min(min_ind, i-1);
        //     }
        // }
        // if(max_ind < min_ind)
        //     return 0;
        // cout<<max_ind<<" "<<min_ind<<endl;
        // return max_ind - min_ind + 1;
    }
};