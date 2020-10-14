
// Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
// O(v+E) time complexity



class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        vector<bool> vis(n, false);
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back({connections[i][1], 0});
            adj[connections[i][1]].push_back({connections[i][0], 1});
        }
        
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int changes=0;
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(int i=0; i<adj[top].size(); i++)
            {
                if(!vis[adj[top][i].first])
                {
                    q.push(adj[top][i].first);
                    if(adj[top][i].second==0)   
                    {
                        changes++;
                    }
                    vis[adj[top][i].first] = true;
                }
            }
        }
        
        return changes;
        
    }
};


