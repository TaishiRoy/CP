
// Friend Circles
// more at https://leetcode.com/problems/friend-circles/


class Solution {
public:
    
    void DFS(vector<vector<int>> &adj, int id, vector<int> &vis)
    {
        vis[id]=1;
        for(int i=0; i<adj[id].size(); i++)
        {
            
            if(vis[adj[id][i]]==0)
            {
                vis[adj[id][i]] = 1;
                DFS(adj, adj[id][i], vis);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        vector<vector<int>> adj(M.size());
        
        for(int i=0; i<M.size(); i++)
        {
            for(int j=i+1; j<M[0].size(); j++)
            {
                if(M[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }
        
        
        int count=0;
        vector<int> vis(M.size(), 0);
        for(int i=0; i<adj.size(); i++)
        {
            
            if(vis[i]==0) 
            {
                
                vis[i]=1;
                DFS(adj, i, vis);
                count++;
            }
        }
        
        return count;
    }
};
