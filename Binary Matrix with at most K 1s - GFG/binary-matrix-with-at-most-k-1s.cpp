// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
  bool isValid(int i, int j, int R, int C)
  {
      if(i<0 || j<0 || i>=R || j>=C)
        return false;
      return true;
  }
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        // code here
        for(int i=1; i<R; i++)
            M[i][0]+= M[i-1][0];
         for(int i=1; i<C; i++)
            M[0][i]+= M[0][i-1];
        for(int i=1; i<R; i++)
        {
            for(int j=1; j<C; j++)
            {
                M[i][j]+= M[i-1][j]+M[i][j-1]-M[i-1][j-1];
            }
        }
        vector<int>ans;
        for(int i=0; i<Q; i++)
        {
            int x = q_i[i];
            int y = q_j[i];
            int count = 0;
            int one_counts = M[x][y];
            if(x-1>=0)
                one_counts-= M[x-1][y];
            if(y-1>=0)
                one_counts-= M[x][y-1];
            queue<pair<int,int>> q;
            if(isValid(x-1,y-1,R,C)) {
                q.push({x-1,y-1});
                one_counts+= M[x-1][y-1];
            }
            if(isValid(x+1,y+1,R,C))
                q.push({x+1,y+1});
            if(one_counts>K) {
                ans.push_back(0);
                continue;
            }
            count++;
            while(!q.empty())
            {
                if(q.size()<2) {
                    break;
                }
                pair<int,int>up;
                pair<int,int>down;
                up = q.front();
                q.pop();
        
                down = q.front();
                q.pop();
                one_counts = M[down.first][down.second];
                if(up.first-1>=0)
                    one_counts-= M[up.first-1][down.second];
                if(up.second-1>=0)
                    one_counts-= M[down.first][up.second-1];
                if(isValid(up.first-1,up.second-1,R,C))
                    one_counts+=M[up.first-1][up.second-1];
                if(one_counts>K) {
                    break;
                }
                count+=2;
                if(isValid(up.first-1,up.second-1,R,C))
                    q.push({up.first-1,up.second-1});
                if(isValid(down.first+1,down.second+1,R,C))
                    q.push({down.first+1,down.second+1});
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends