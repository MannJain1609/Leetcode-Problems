class Solution {
private:
    // bool isAdjacent(string word1, string word2, int wordlen)
    // {
    //     int count = 1;
    //     for(int i=0; i<wordlen; i++)
    //     {
    //         if(word1[i] == word2[i])
    //             continue;
    //         else
    //             count--;
    //         if(count<0)
    //             return false;
    //     }
    //     return true;
    // }
    // void getAdjacents(string word, int wordlen, vector<string>& wordList, 
    //                          unordered_map<string,bool>& visited, int size, queue<string>& q)
    // {
    //     for(int i=0; i<size; i++)
    //     {
    //         if(!visited[wordList[i]] && isAdjacent(word,wordList[i],wordlen))
    //         {
    //             visited[wordList[i]] = true;
    //             q.push(wordList[i]);
    //         }
    //     }
    // }
    
    void addAdjacents(string word, int wordlen, vector<string>& wordList, unordered_map<string,bool>& 
                      visited, unordered_set<string>& words, int size, queue<string>& q)
    {
        for(int i=0; i<wordlen; i++)
        {
            char real = word[i];
            for(char c = 'a'; c<='z'; c++)
            {
                word[i] = c;
                if(words.count(word)==1 && !visited[word])
                {
                    visited[word] = true;
                    q.push(word);
                }
            }
            word[i] = real;
        }
    }
    int bfs(string beginWord, string endWord, vector<string>& wordList, 
            unordered_set<string>& words, int wordlen, int size)
    {
        int len = 1;
        queue<string>q;
        unordered_map<string,bool>visited;
        q.push(beginWord);
        visited[beginWord] = true;
        while(!q.empty())
        {
            int l = q.size();
            for(int i=0; i<l; i++)
            {
                string word = q.front();
                q.pop();
                //cout<<word<<" ";
                if(word == endWord) {
                    return len;
                }
                //getAdjacents(word,wordlen,wordList,visited,size,q);
                addAdjacents(word,wordlen,wordList,visited,words,size,q);
            }
            //cout<<"\n";
            len++;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wordlen = beginWord.size();
        int size = wordList.size();
        unordered_set<string> words;
        for(int i=0; i<size; i++)
        {
            words.insert(wordList[i]);
        }
        return bfs(beginWord,endWord,wordList,words,wordlen,size);
    }
};