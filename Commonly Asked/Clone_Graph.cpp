
// function to clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
// O(V+E) time complexity


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
    mp[node]=clone;
    
    while(!q.empty())
    {
        auto top = q.front();
        
        q.pop();
        {
            for(int i=0; i<top->neighbors.size(); i++)
            {
                if(mp.count(top->neighbors[i])==0)
                {
                    UndirectedGraphNode* cloneneigh = new UndirectedGraphNode(top->neighbors[i]->label);
                    mp[top->neighbors[i]] = cloneneigh;
                    q.push(top->neighbors[i]);
                    mp[top]->neighbors.push_back(cloneneigh);
                }
                else
                {
                    mp[top]->neighbors.push_back(mp[top->neighbors[i]]);
                }
            }
        }
    }
    
    return mp[node];

}

