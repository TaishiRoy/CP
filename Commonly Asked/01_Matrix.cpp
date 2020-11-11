// 01 Matrix
// O(r⋅c) Space complexity 
// O(r⋅c) Time complexity


// more at https://leetcode.com/problems/01-matrix/submissions/

class Solution {
public:
    
    int getNearest(vector<vector<int>>& mat, int i, int j)
    {
        static int arr[] = { -1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        q.push({i,j});
        vis[i][j]=1;
        int res=0;
        while(!q.empty())
        {
            int n=q.size();
            // cout << n << endl;
            res++;
            while(n--)
            {
                auto top = q.front();
                q.pop();
                int disti=0, distj=0;
                for(int i=0; i<4; i++)
                {
                    disti = top.first+arr[i];
                    distj = top.second+arr[i+1];
                    if(disti<0 || distj<0 || disti>=mat.size() || distj>=mat[0].size() || vis[disti][distj]==1) continue;
                    if(mat[disti][distj]==0)    return res;
                    q.push({disti, distj});
                    vis[disti][distj] = 1;
                }
            }
            
        }
        
        return res;
        
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) 
        {
            return matrix;
        }
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        static int arr[] = { -1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]==0) 
                {
                    mat[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty())
        {
                auto top = q.front();
                q.pop();
                int disti=0, distj=0;
                for(int i=0; i<4; i++)
                {
                    disti = top.first+arr[i];
                    distj = top.second+arr[i+1];
                    if(disti<0 || distj<0 || disti>=mat.size() || distj>=mat[0].size()) continue;
                    if(mat[disti][distj]>mat[top.first][top.second]+1)
                    {
                        mat[disti][distj] = mat[top.first][top.second]+1;
                        q.push({disti, distj});
                    }
                }
                    
        }
        
        return mat;
    }
};
