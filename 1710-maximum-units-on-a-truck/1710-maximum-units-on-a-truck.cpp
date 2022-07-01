class Solution {
private:
    static bool cmp (vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);  
        int size = boxTypes.size();
        int boxes = 0, units=0;
        for(int i=0; i<size; i++)
        {
            if(truckSize<=0)
                break;
            int box = boxTypes[i][0]>truckSize ? truckSize : boxTypes[i][0];
            truckSize-=box;
            units+=box*(boxTypes[i][1]);
        }
        return units;
    }
};