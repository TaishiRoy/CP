// Longest Absolute File Path
// more at https://leetcode.com/problems/longest-absolute-file-path/submissions/

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> stk;
        int res=0, curr=0;
        bool gotFile = false;
        for(int i=0; i<input.length(); i++)
        {
            
            if(input[i] == '\n')
            {
                if(!stk.empty())    stk.push(stk.top()+1+curr);
                else    stk.push(curr);
                if(gotFile)
                {
                    res = max(res, stk.top());
                }
                gotFile = false;
                curr=0;
                int lev = 0;
                while(input[i+1]=='\t')
                {
                    lev++;
                    i++;
                }
                while(lev!=stk.size())
                {
                    stk.pop();
                }
            }
            else
            {
                curr++;
                if(input[i]=='.')
                {
                    gotFile=true;
                }
            }
        }
        
        if(gotFile)
        {
            if(!stk.empty())   res = max(res, stk.top()+1+curr);
                else    res=max(res, curr);
            
        }
        
        return res;
    }
};
