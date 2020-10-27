
// Subset Sum Problem 2
// more at https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// User function Template for C++

class Solution{
public:
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0; i<N; i++)
        {
            sum+=arr[i];
        }
        if(sum%2==1)    return 0;
        
        bool dp[N+1][sum/2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=N; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=(sum/2); i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=sum/2; j++)
            {
                
                dp[i][j] = dp[i-1][j];
                
                if(j>=arr[i-1] && dp[i][j]==0)
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[N][sum/2];
        
    }
};
