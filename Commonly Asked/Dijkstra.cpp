
// Implementing Dijkstra (Adjacency Matrix) 

// Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.
// more at https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?track=DSASP-Graph&batchId=154#
 
// O(Elogv) time complexity



vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
     q.push({0, src});
    
    while(!q.empty())
    {
        auto curr = q.top();
        q.pop();
        if(dist[curr.second]<curr.first)   continue;
        for(int i=0; i<V; i++)
        {
            if(g[curr.second][i]>0)
            {
                if(dist[i] > curr.first + g[curr.second][i])
                {
                    dist[i] = curr.first + g[curr.second][i];
                    q.push({dist[i], i});
                }
            }
        }
    }
    
    return dist;
}
