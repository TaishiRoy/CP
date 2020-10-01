
// function to solve the subset sum problem
// more at https://www.interviewbit.com/problems/subset-sum-problem/
// O(Bn) time complaxity O(Bn) auxiliary space

int solve(vector<int> &A, int B) {
    int dp[B+1][A.size()+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=B; i++)
    {
        for(int j=0; j<=A.size(); j++)
        {
            if(i==0)    dp[i][j]=1;
            else if(j==0)   dp[i][j]=0;
            else if(A[j-1]<=i)
            {
                dp[i][j] = max(dp[i-A[j-1]][j-1], dp[i][j-1]);
            }
            else    dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    return dp[B][A.size()];
}
