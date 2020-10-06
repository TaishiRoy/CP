

// solution for Rotting Oranges problem
// more at https://leetcode.com/problems/rotting-oranges/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.size()==0)  return 0;
        bool visited[grid.size()][grid[0].size()];
        memset(visited, false, sizeof(visited));
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==2 && !visited[i][j])
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int lev = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                auto top = q.front();
                q.pop();
                int a = top.first, b=top.second;
                if(a>0 && grid[a-1][b]==1 && !visited[a-1][b])
                {
                    q.push({a-1, b});
                    visited[a-1][b] = true;
                }
                if(b>0 && grid[a][b-1]==1 && !visited[a][b-1])
                {
                    q.push({a, b-1});
                    visited[a][b-1] = true;
                }
                if(a<grid.size()-1 && grid[a+1][b]==1 && !visited[a+1][b])
                {
                    q.push({a+1, b});
                    visited[a+1][b] = true;
                }
                if(b<grid[0].size()-1 && grid[a][b+1]==1 && !visited[a][b+1])
                {
                    q.push({a, b+1});
                    visited[a][b+1] = true;
                }
            }
            lev++;
        }
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j]==1) 
                {
                    return -1;
                }
            }
        }
        
        return lev>0?lev-1:0;
    }
};
