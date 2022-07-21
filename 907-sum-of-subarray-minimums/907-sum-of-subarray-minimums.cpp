class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        //number of left and right larget till next smaller
        //in left, equal case is also considered
        int left[size],right[size];
        for(int i=0; i<size; i++)
        {
            left[i] = 1;
            right[i] = 1;
        }
        stack<int>s1;
        stack<int>s2;
        s1.push(0);
        for(int i=1; i<size; i++)
        {
            while(!s1.empty() && arr[s1.top()]>=arr[i])
                s1.pop();
            if(!s1.empty())
                left[i] = i - s1.top();
            else
                left[i] = i + 1;
            s1.push(i);
        }
        s2.push(size-1);
        for(int i=size-2; i>=0; i--)
        {
            while(!s2.empty() && arr[s2.top()]>arr[i])
                s2.pop();
            if(!s2.empty())
                right[i] = s2.top() - i;
            else
                right[i] = size - i;
            s2.push(i);
        }
        int ans = 0,MOD = 1e9+7;
        for(int i=0; i<size; i++)
        {
            long long x= ((long long)arr[i] * (left[i] * right[i])%MOD)%MOD;
            x= (ans + x)%MOD;
            ans = (int)x;
        }
        return ans;
    }
};

//x+y-1 + (x-1)*(y-1) = xy