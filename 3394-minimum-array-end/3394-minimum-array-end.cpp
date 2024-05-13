class Solution {
public:
    void fill_map(vector<int>& bitmap, int x)
    {
        int i = 0;
        while(x  > 0)
        {
            bitmap[i] = (x&1);
            x = (x>>1);
            i++;
        }
    }
    
    void to_bits(int n, vector<int>& v)
    {
        while(n > 0)
        {
            v.push_back((n&1));
            n = (n>>1);
        }
    }

    long long convert_to_num(vector<int>& v) {
        while(v.back() == 0) v.pop_back();
        reverse(v.begin(), v.end());
        long long res = 0;
        for(int i = 0; i < (int)(v.size()); i++) {
            res = (res << 1) + v[i];
        }
        return res;
    }

    
    long long minEnd(int n, int x) {
        long long ans = x;
        if(n == 1)
            return x;
        vector<int>bitmap(64,0);
        fill_map(bitmap,x);
        
        vector<int> v;
        to_bits(n-1,v);
        
        vector<int>zero_pos;
        for(int i=0; i<64; i++)
        {
            if(i <= 32)
            {
                if((bitmap[i] == 0))
                    zero_pos.push_back(i);
            }
            else {
                zero_pos.push_back(i);
            }
        }


        int size = v.size();
        int zero_size = zero_pos.size();
        for(int i=0, j=0; i<zero_size, j<size; i++, j++)
        {
            bitmap[zero_pos[i]] = v[j];
        }

       
        ans = convert_to_num(bitmap);
        return ans;
    }
};