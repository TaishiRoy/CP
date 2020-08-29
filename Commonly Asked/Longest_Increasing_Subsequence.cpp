
// function to find the longest increasing subsequence with dp
// more at https://www.interviewbit.com/problems/longest-increasing-subsequence/
// O(n^2) time complexity O(n) auxiliary space

int lis(const vector<int> &A) {
    
    int dp[A.size()]={0};
    for(int i=0; i<A.size(); i++)
    {
        dp[i]=1;
        for(int j=0; j<i; j++)
        {
            if(A[j]<A[i])
            {
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp, dp+A.size());
}
