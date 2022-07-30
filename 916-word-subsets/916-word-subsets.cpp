class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int maxB[26] = {0};
        for(string ss : words2)
        {
            int count[26] = {0};
            for(char c: ss)
            {
                count[c-'a']++;
                maxB[c-'a'] = max(maxB[c-'a'],count[c-'a']);
            }
            // for(int i=0; i<26; i++)
            //     maxB[i] = max(maxB[i],count[i]);
        }
        
        for(string word : words1)
        {
            int freq[26] = {0};
            for(char c : word)
            {
                freq[c-'a']++;
            }
            int flag = 1;
            for(int i=0; i<26; i++)
            {
                if(freq[i] < maxB[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};

