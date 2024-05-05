class Solution {
public:
   
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int size = beans.size();
        long long sum = 0;
        for(int i=0; i<size; i++)
        {
            sum += beans[i];
        }
        long long ans = sum;
        for(int i=0; i<size; i++) {
            ans = min(ans, sum - (size-i)*(long long)beans[i]);
        }
        return ans;
    }
};