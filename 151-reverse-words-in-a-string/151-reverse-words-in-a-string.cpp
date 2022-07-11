class Solution {
public:
    string reverseWords(string s) {
        stack<string>words;
        int size = s.size();
        string word = "";
        for(int i=0; i<size; i++)
        {
            if(isspace(s[i])) {
                if(word!="")
                    words.push(word);
                word = "";
                continue;
            }
            word+=s[i];
        }
        if(word!="")
            words.push(word);
        word = "";
        while(!words.empty())
        {
            word+=words.top()+' ';
            words.pop();
        }
        word.resize(word.size()-1);
        return word;
    }
};