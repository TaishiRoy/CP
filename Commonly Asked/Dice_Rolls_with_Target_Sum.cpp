

// function to get Number of Dice Rolls With Target Sum
// more at https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// O(dft) time complexity O(dt) auxiliary space


class Solution {
public:
    int dp[601][1001];
    
    int numRollsToTarget(int d, int f, int target) {
        if (d == 0)
		    return (target == 0);
        if (target < 0 || f * d < target || d > target)
		    return 0;
        if(d==1)
        {
            if(target<=f)   
            {
                dp[d][target] = 1;
                return 1;
            }
            else    
            {
                dp[d][target]=0;
                return 0;
            }
        }
        if(dp[d][target]!=0)    return dp[d][target];
        
        int res=0;
        for(int i=1; i<=f; i++)
        {
            res+= numRollsToTarget(d-1, f, target-i);
            res%= 1000000007;
        }
        dp[d][target] = res;
        return res;
         
    }
};
