// class Solution {
// public:
//     static bool cmp(vector<int> &a, vector<int>& b)
//     {
//         if(a[0]!=b[0])
//             return a[0] < b[0];
//         return a[1] > b[1];
//     }
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         int numWeak = 0;
//         int size = properties.size();
//         sort(properties.begin(),properties.end(),cmp);
//         unordered_map<int,int>mp;
//         stack<int>s;
//         for(int i=size-1; i>=0; i--)
//         {
//             while(!s.empty() && properties[s.top()][1] <= properties[i][1])
//                 s.pop();
//             if(s.empty())
//                 mp[i] = -1;
//             else
//                 mp[i] = s.top();
//             s.push(i);
//         }
//         for(int i=0; i<size; i++)
//         {
//             if(mp[i]!=-1)
//                 numWeak++;
//         }
//         return numWeak;
      
//     }
// };

class Solution {
public:
     static bool cmp(const vector<int> &a, const vector<int>& b)
    {
        if(a[0]!=b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort in ascending order of attack, 
        // If attack is same sort in descending order of defense
        sort(properties.begin(), properties.end(), cmp);
             
        int weakCharacters = 0;
        int maxDefense = 0;
        for (int i = (int)properties.size() - 1; i >= 0; i--) {
            // Compare the current defense with the maximum achieved so far
            if (properties[i][1] < maxDefense) {
                weakCharacters++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return weakCharacters;
    }
};