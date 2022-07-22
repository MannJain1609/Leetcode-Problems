class Solution {
public:
    string removeDuplicates(string s) {
        string a = "";
        for (auto c:s) {
            if (a.back() == c)
            {a.pop_back();}
            else 
            {a.push_back(c);}
        }
            
        return a;
    }
};