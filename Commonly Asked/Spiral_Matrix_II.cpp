
// solution to Spiral Matrix II problem
// more at https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> mat;
        for(int i=0; i<n; i++)
        {
            mat.push_back(row);
        }
        
        int topR=0, bottomR=n-1, rightC=n-1, leftC=0, curr=1;
        
        while(topR<=bottomR && leftC<=rightC)
        {
            for(int i=leftC; i<=rightC; i++)
            {
                mat[topR][i] = curr++;
            }
            topR++;
            for(int i=topR; i<=bottomR; i++)
            {
                mat[i][rightC] = curr++;
            }
            rightC--;
            
            if(leftC<=rightC)
            {
                for(int i=rightC; i>=leftC; i--)
                {
                    mat[bottomR][i] = curr++;
                }
                bottomR--;
            }
            
            if(topR<=bottomR)
            {
                for(int i=bottomR; i>=topR; i--)
                {
                    mat[i][leftC] = curr++;
                }
                leftC++;
            }
        }
        
        return mat;
    }
};
