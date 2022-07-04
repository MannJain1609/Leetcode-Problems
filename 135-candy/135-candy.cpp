class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int>forward(size,1);
        vector<int>backward(size,1);
        for(int i=0; i<size-1; i++)
        {
            if(ratings[i+1]>ratings[i])
            {
                forward[i+1] = forward[i]+1;
            }
        }
        for(int i = size-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1])
                backward[i] = backward[i+1] + 1;
        }
        int candy = 0;
        for(int i=0; i<size; i++)
        {
            candy+= max(forward[i],backward[i]);
        }
        return candy;
    }
};