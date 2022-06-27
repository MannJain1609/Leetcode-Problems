class Solution {
public:
    int minPartitions(string n) {
        int size = n.size();
        int max_digit = 0;
        for(int i=0; i<size; i++)
        {
            int a = n[i] - '0';
            max_digit = max(a,max_digit);
        }
        return max_digit;
    }
};