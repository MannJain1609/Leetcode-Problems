class MedianFinder {
public:
    map<int,int>mp;
    int count;
    MedianFinder() {
        this->count = 0;
    }
    
    void addNum(int num) {
        mp[num]++;
        count++;
    }
    
    double findMedian() {
        int mid = (count+1)/2;
        int x = 0;
        auto it = mp.begin();
        while(x < mid) {
            x += it->second;
            if(x < mid) {
                it++;
            }
        }
        if((count&1))
            return (double)(it->first);
        else{
            if(mid == x)
            {
                auto nextIt = next(it);
                double ans = (it->first + nextIt->first)/2.0;
                return ans;
            }
            else {
                return (double)(it->first);
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */