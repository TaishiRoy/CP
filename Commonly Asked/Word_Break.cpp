
// Word Break
// more at https://leetcode.com/problems/word-break/submissions/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length());
        
        for(int i=0; i<s.length(); i++)
        {
            if(!dp[i] && find(wordDict.begin(), wordDict.end(), s.substr(0, i+1))!=wordDict.end())  dp[i]=true;
            
            if(dp[i])
            {
                if(i==s.length()-1)  return true;
                
                for(int j=i+1; j<s.length(); j++)
                {
                    if(!dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(i+1, j-i))!=wordDict.end())    dp[j]=true;
                    if(dp[j] && j==s.length()-1)  return true;
                }
            }
        }
        
        return false;
    }
};
