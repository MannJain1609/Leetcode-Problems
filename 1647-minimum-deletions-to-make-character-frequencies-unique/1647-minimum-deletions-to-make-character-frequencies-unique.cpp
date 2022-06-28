class Solution {
public:
    int minDeletions(string s) {
        int size = s.size();
        int freq[26]={0};
        for(int i=0; i<size; i++)
        {
            freq[s[i]-'a']++;
        }
        priority_queue<int> pq;
        for(int i=0; i<26; i++)
        {
            if(freq[i]>0) {
                pq.push(freq[i]);
            }
        }
        int min_deletions = 0;
        while(!pq.empty())
        {
            int y = pq.top();
            pq.pop();
            if(!pq.empty() && y==pq.top())
            {
                y--;
                min_deletions++;
                if(y>0)
                    pq.push(y);
            }
        }
        return min_deletions;
    }
};