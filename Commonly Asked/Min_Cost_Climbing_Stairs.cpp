

// Min Cost Climbing Stairs
// more at https://leetcode.com/problems/min-cost-climbing-stairs/submissions/
// O(n) time complexity O(n) auxiliary space top down dp

class Solution {
public:
    
    int util(vector<int>& cost, vector<int>& dp, int pos)
    {
        if(pos<=0)  return 0;
        if(dp[pos]!=-1) return dp[pos];
        dp[pos] = min((util(cost, dp, pos-2)+cost[pos-2]), 
                            (util(cost, dp, pos-1)+cost[pos-1]));
        return dp[pos];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size()+1, -1);
        if(cost.size()>=1)   dp[0] = 0;
        if(cost.size()>=2)   dp[1] = 0;
        return util(cost, dp, cost.size());
    }
};

