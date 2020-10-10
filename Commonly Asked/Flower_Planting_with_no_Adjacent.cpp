
// Flower Planting With No Adjacent


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> adj[N];
        
        for(int i=0; i<paths.size(); i++)
        {
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        vector<int> res(N, 1);
        queue<int> q;
        q.push(0);
        bool visited[N];
        memset(visited, false, N);
        
        for(int x=0; x<N; x++)
        {
            if(!visited[x])
            {
                q.push(x);
                while(!q.empty())
                {
                    int t = q.front();
                    // cout << t << endl;
                    q.pop();
                    if(!visited[t])
                    {
                        for(int i=1; i<=4; i++)
                        {

                            bool flag=false;
                            for(int j=0; j<adj[t].size(); j++)
                            {
                                // cout << adj[t][j] << " jkj " << visited[adj[t][j]] << " kj " << res[adj[t][j]] << endl;
                                if(visited[adj[t][j]]==true && res[adj[t][j]]==res[t])
                                {

                                    flag=true;
                                    res[t] = (res[t]+1) > 4 ? (res[t]+1)%5 +1 : res[t]+1;
                                    break;
                                }
                            }
                            if(!flag)   break;
                        }
                        visited[t]=true;
                        for(int i=0; i<adj[t].size(); i++)
                        {
                            if(!visited[adj[t][i]])
                            {
                                q.push(adj[t][i]);
                            }
                        }
                    }
                }
            }
        }
        
                            
        return res;
        
    }
};
