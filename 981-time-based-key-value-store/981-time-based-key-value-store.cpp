class TS {
    public:
    unordered_map<int,string> u;
    string fetch(int time)
    {
        if(u.find(time) != u.end())
            return u[time];
        for(int i=time-1; i>=0; i--)
        {
            if(u.find(i) != u.end())
                return u[i];
        }
        return "";
    }
    void insert(int key, string value)
    {
        u[key] = value;
    }
};
class TimeMap {
public:
    unordered_map<string,TS> mp;
     
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        string v = mp[key].fetch(timestamp);
        return v;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */