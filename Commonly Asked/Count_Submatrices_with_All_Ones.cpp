
// Count Submatrices With All Ones
// https://leetcode.com/problems/count-submatrices-with-all-ones/



class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=mat[i].size()-2; j>=0; j--)
            {
                if(mat[i][j]!=0)
                {
                    mat[i][j]+=mat[i][j+1];
                }
            }
        }
        
        
        int res=0;
        for(int j=0; j<mat[0].size(); j++)
        {
            stack<pair<int, int>> stk;
            int curr=0;
            for(int i=mat.size()-1; i>=0; i--)
            {
                int c=0;
                while(!stk.empty() && stk.top().first > mat[i][j])
                {
                    curr -= (stk.top().second + 1) * (stk.top().first - mat[i][j]); 
  
                    c += stk.top().second + 1; 
                    stk.pop();  
                }
                curr += mat[i][j]; 
  
                res += curr; 
  
                stk.push({ mat[i][j], c }); 
            }
            
        }
        
        return res;
    }
};
