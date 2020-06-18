// function to get the longest palindromic substring of a string
// using tabulation DP
// O(n) time O(n^2) auxillary space

string longestPalindrome(string A) {
    
    vector<vector<bool>> dp(A.size(), vector<bool>(A.size()));
    
    // base case, palindrome of length 1
    for(int i=0; i<A.size(); i++)
    {
        dp[i][i] = true;
    }
    
    int maxLen = 1, start = 0;
    // base case, palindrome of length 2
    for(int i=0; i<A.size()-1; i++)
    {
        if(A[i]==A[i+1])
        {
            dp[i][i+1] = true;
            if(maxLen<2)
            {
                maxLen = 2;
                start = i;
            }
        }
    }
    
    for(int k=3; k<=A.size(); k++)
    {
        for(int i=0; i<A.size()-k+1; i++)
        {
            int j= i+k-1;
            if(A[i] == A[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;
                if(k>maxLen)
                {
                    maxLen = k;
                    start = i;
                }
            }
        }
    }
    
    return A.substr(start, maxLen);
}
