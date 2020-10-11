
// Network Delay Time
// https://leetcode.com/problems/network-delay-time/
// O(ELogV)


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        bool visited[N];
        memset(visited, false, sizeof(visited));
        vector<pair<int, int>> adj[N];
        for(int i=0; i<times.size(); i++)
        {
            adj[times[i][0]-1].push_back({times[i][2], times[i][1]-1});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, K-1});
        
        int res=0;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            if(visited[top.second]) continue;
            
            res = top.first;
            visited[top.second]=true;
            for(auto it:adj[top.second])
            {
                pq.push({it.first+top.first, it.second});
            }
        }
        
        for(int i=0; i<N; i++)
        {
            if(!visited[i]) return -1;
        }
        return res;
    }
};
