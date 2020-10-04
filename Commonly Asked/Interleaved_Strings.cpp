
// function to detect if two strings form an interleaved string
// more at https://practice.geeksforgeeks.org/problems/interleaved-strings/1
// Time Complexity: O(N * M) Auxiliary Space: O(N * M)


bool isInterleave(string A, string B, string C) 
{
    bool dp[A.length()+1][B.length()+1];
    memset(dp, false, sizeof(dp));
    
    dp[0][0] = true;
    for(int i=1; i<=B.length(); i++)
    {
        if(C[i-1] == B[i-1])
        {
            dp[0][i] = dp[0][i-1];
        }
    }
    for(int i=1; i<=A.length(); i++)
    {
        if(C[i-1] == A[i-1])
        {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    
    for(int i=1; i<=A.length(); i++)
    {
        for(int j=1; j<=B.length(); j++)
        {
            if(C[i+j-1]==A[i-1] && dp[i-1][j])  dp[i][j] = true;
            else if(C[i+j-1]==B[j-1] && dp[i][j-1]) dp[i][j] = true;
        }
    }
    return dp[A.length()][B.length()];
}

