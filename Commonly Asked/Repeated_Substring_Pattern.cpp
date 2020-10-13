
// Repeated Substring Pattern
// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
// You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
// O(n^2) time complexity O(1) auxiliary space



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool flag = true;
        for(int len=s.length()/2; len>0; len--)
        {
            if(s.length()%len!=0)    continue;
            flag = true;
            for(int k=0; k<s.length()/len; k++)
            {
                for(int i=0; i<len; i++)
                {
                    if(s[i]!=s[k*len+i])    
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)   break;
                if(k==s.length()/len - 1)   return true;
            }
        }
        return false;
    }
};
