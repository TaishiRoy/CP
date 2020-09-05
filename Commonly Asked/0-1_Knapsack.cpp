
// function to sove 0-1 Knapsack problem
// more at https://www.interviewbit.com/problems/0-1-knapsack/
// O(n^2) time complexity O(n*C) auxiliary space

int solve(vector<int> &A, vector<int> &B, int C) {
    
    int dp[A.size()+1][C+1];
    
    for(int item=0; item<=A.size(); item++)
    {
        for(int wt=0; wt<=C; wt++)
        {
            if(wt==0 || item==0)   dp[item][wt]=0;
            else if(B[item-1]<=wt)
            {
                dp[item][wt]=max(A[item-1]+dp[item-1][wt-B[item-1]], dp[item-1][wt]);
            }
            else
            {
                dp[item][wt]=dp[item-1][wt];
            }
        }
    }
    return dp[A.size()][C];
    
}

