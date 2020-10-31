

// Cut Off Trees for Golf Event
// more at https://leetcode.com/problems/cut-off-trees-for-golf-event/


class Solution {
public:
    
    long long int getDist( vector<vector<int>> forest, int sr, int sc, int dr, int dc)
    {
        if(sr==dr && sc==dc)    return 0;
        vector<vector<bool>> vis(forest.size(), vector<bool>(forest[0].size(), false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;
        
        long long int steps=0;
        while(!q.empty())
        {
            steps++;
            // cout << steps << endl;
            int n=q.size();
            while(n--)
            {
                int r=q.front().first, c=q.front().second;
                q.pop();
                // cout << r << " " << c << endl;
                int dist[] = {-1, 0, 1, 0, -1};
                for(int i=0; i<4; i++)
                {
                    int currr=r+dist[i], currc=c+dist[i+1];
                    // cout << n << " " << n << endl;
                    if(currr==dr && currc==dc)  return steps;
                    if(currr<0 || currr>=forest.size() || currc<0 || currc>=forest[0].size() || vis[currr][currc] || forest[currr][currc]==0)  continue;
                    q.push({currr, currc});
                    vis[currr][currc] = true;
                }
            }
        }
        return -1;
    }
    
    
    int cutOffTree(vector<vector<int>>& forest) {
        
        if(forest.size()==0)    return 0;
        vector<vector<int>> tree;
        for(int i=0; i<forest.size(); i++)
        {
            for(int j=0; j<forest[0].size(); j++)
            {
                if(forest[i][j]>0)  tree.push_back({forest[i][j], i, j});
            }
        }
        
        sort(tree.begin(), tree.end());
        
        long long int res=0;
        int row=0, col=0;
        for(int i=0; i<tree.size(); i++)
        {
            // cout << res << endl;
            long long int steps = getDist(forest, row, col, tree[i][1], tree[i][2]);
            if(steps==-1)   return -1;
            res+= steps;
            row=tree[i][1], col=tree[i][2];
            
        }
        
        return res;
    }
};
