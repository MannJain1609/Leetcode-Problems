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
            width+=size+1;
            if(width>maxWidth+1)
            {
                width-= (size+1);
                int req_spaces = maxWidth - width + 1;
                int extra = 0;
                if(count>1) {
                    req_spaces = (maxWidth - width + count)/(count-1);
                    extra = (maxWidth - width + count)%(count-1);
                }
                // cout<<req_spaces<<" ";
                string line = "";
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
                width = size+1;
                count = 0;
            }
            q.push(word);
            count++;
            //cout<<word<<" "<<width<<endl;
        }
        
        string line = "";
        int c = 0;
        while(!q.empty())
        {
            line+= q.front()+' ';
            c+= q.front().size() + 1;
            q.pop();
        }
        if(c>maxWidth)
            line.resize(line.size()-1);
        else if(c<maxWidth)
            line.append(maxWidth-c,' ');
        ans.push_back(line);
        return ans;
    }
};