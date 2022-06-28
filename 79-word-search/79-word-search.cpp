class Solution {
private:
    //bool isTrue = false;
    bool helper(vector<vector<char>>& board, string word, vector<vector<bool>>& visited,
                int m, int n, int row, int col, int ind, int size) 
    {
        if(ind==size)
        {
            //isTrue = true;
            return true;
        }
        if(row<0 || row>=m || col<0 || col>=n || visited[row][col] || 
           word[ind]!=board[row][col])
            return false;

        // if(word[ind] == board[row][col])
        //     ind++
        //cout<<row<<" "<<col<<endl;
        visited[row][col] = true;
        if(helper(board,word,visited,m,n,row-1,col,ind+1,size) ||
           helper(board,word,visited,m,n,row+1,col,ind+1,size) ||
           helper(board,word,visited,m,n,row,col-1,ind+1,size) ||
           helper(board,word,visited,m,n,row,col+1,ind+1,size))
            return true;
        visited[row][col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int size = word.size();
        // unordered_map<char, int> boardCharCount;
        // for (int i = 0; i < board.size(); i++) {
        //     for (int j = 0; j < board[0].size(); j++) {
        //         boardCharCount[board[i][j]]++;
        //     }
        // }
        // unordered_map<char, int> wordCharCount;
        // for (int i = 0; i < word.size(); i++) {
        //     wordCharCount[word[i]]++;
        // }
        // for (auto keyVal : wordCharCount) {
        //     if (boardCharCount[keyVal.first] < keyVal.second) {
        //         return false;
        //     }
        // }

        //cout<<"m: "<<m<<"n: "<<n<<endl;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == word[0] && helper(board,word,visited,m,n,i,j,0,size))
                    return true;
            }
        }
        return false;
    }
};