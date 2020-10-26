
// Critical Connections in a Network
// more at https://leetcode.com/problems/critical-connections-in-a-network/
// Using Tarjan’s algo for bridges
// O(v+e) time complexity


class Solution {
public:
    
    void tarjanDfs(int time, int curr, int par, vector<vector<int>>& adj, vector<bool>& visited, 
                   vector<int> &disc, vector<int> &low, vector<vector<int>> &res)
    {
        time++;
        visited[curr] = true;
        disc[curr] = time;
        low[curr] = time;
        
        for( auto nbr : adj[curr])
        {
            if(nbr==par)    continue;
            
            if(!visited[nbr])
            {
                tarjanDfs(time, nbr, curr, adj, visited, disc, low, res);
                low[curr] = min(low[nbr], low[curr]);
                
                if(low[nbr]>disc[curr])
                {
                    res.push_back({curr, nbr});
                }
            }
            else
            {
                low[curr] = min(low[curr], low[nbr]);
            }
        }
        return;
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n+1);
        vector<int> disc(n+1);
        vector<int> low(n+1);
        vector<vector<int>> res;
        tarjanDfs(0, 0, -1, adj, visited, disc, low, res);
        return res;
    }
};
