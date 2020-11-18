// Cherry Pickup
// more at https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    int dp[50][50][50];
    
    int util(vector<vector<int>>& grid, int r1, int c1, int r2, int c2)
    {
        if(r1>=grid.size() || c1>=grid.size() || r2>=grid.size() || c2>=grid.size() || 
           r1<0 || c1<0 || r2<0 || c2<0 || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1)
        {
            return dp[r1][c1][c2];
        }
        if(r1==grid.size()-1 && c1==grid.size()-1)  return grid[r1][c1];
        
        int ans = grid[r1][c1] + ((r1==r2)?0:grid[r2][c2]);
        int temp = max(util(grid, r1+1,c1,r2+1, c2), 
                       max(util(grid, r1+1, c1, r2, c2+1), 
                           max(util(grid, r1, c1+1, r2, c2+1), util(grid, r1, c1+1, r2+1, c2))));
        
        dp[r1][c1][c2] = ans+temp;
        return dp[r1][c1][c2];
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(0, util(grid, 0, 0, 0, 0));
    }
};
