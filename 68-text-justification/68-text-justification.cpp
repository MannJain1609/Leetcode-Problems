class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        vector<string>ans;
        int width = 0,count=0;
        queue<string>q;
        
        for(string word : words)
        {
            int size = word.size();
            //considering one space between words in width
            width+=size+1;
            if(width>maxWidth+1)
            {
                width-= (size+1);
                //calculating the req spaces by assuming one word
                int req_spaces = maxWidth - width + 1;
                //stores the extra spaces in case of not evenly distributed
                //count is 1, extra spaces are zero
                int extra = 0;
                //if there are more than one word till now, update req_spaces and extra
                if(count>1) {
                    req_spaces = (maxWidth - width + count)/(count-1);
                    extra = (maxWidth - width + count)%(count-1);
                }
                
                string line = "";
                //for count of characters in line
                int c = 0;
                
                while(!q.empty())
                {
                    line+= q.front();
                    c+= q.front().size();
                    if(c<maxWidth) {
                        if(extra>0) {
                            line+= ' ';
                            extra--;
                            c+= 1;
                        }
                        line.append(req_spaces,' ');
                        c+= req_spaces;
                    }
                    q.pop();
                }
                ans.push_back(line);
                //initaialising for next line
                width = size+1;
                count = 0;
            }
            q.push(word);
            count++;
        }
        
        //Last line case
        //Adding one space in last line between words
        //left justified
        string line = "";
        int c = 0;
        while(!q.empty())
        {
            line+= q.front()+' ';
            c+= q.front().size() + 1;
            q.pop();
        }
        //in case, last space exceeds the max count
        if(c>maxWidth)
            line.resize(line.size()-1);
        else if(c<maxWidth)
            line.append(maxWidth-c,' ');
        ans.push_back(line);
        return ans;
    }
};