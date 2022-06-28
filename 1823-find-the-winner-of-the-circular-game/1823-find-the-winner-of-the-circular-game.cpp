class Solution {
public:
    int findTheWinner(int n, int k) {
        // list<int> circle;
        // for(int i=1; i<=n; i++)
        //     circle.push_back(i);
        // auto it = circle.begin();
        // while(circle.size()>1)
        // {
        //     for(int i=1; i<k; i++)
        //     {
        //         it++;
        //         if(it == circle.end())
        //             it = circle.begin();
        //     }
        //     circle.erase(it++);
        //     if(it == circle.end())
        //         it = circle.begin();
        // }
        // return circle.back();
        
        //Josephus Problem
        if (n==1)
            return 1;
        
        return 1+(findTheWinner(n-1,k)+k-1)%n;
    }
};
