class Solution {
public:
    bool rotateString(string s, string goal) {
        //circular string
        s+=s;
        return s.size() == 2 * goal.size() && s.find(goal)!=string::npos;
    }
};