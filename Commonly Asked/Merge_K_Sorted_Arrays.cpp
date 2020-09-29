

// function to merge K sorted arrays
// O(mn) time complexity O(m) auxiliary space


vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> res;
    priority_queue<
        pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>
        >  mnhp;

        
    for(int i=0; i<A.size(); i++)
    {
        mnhp.push({A[i][0], {i, 0}});
    }
    
    while(!mnhp.empty())
    {
        auto pick = mnhp.top();
        res.push_back(pick.first);
        mnhp.pop();
        if(pick.second.second+1 < A[0].size())  
            mnhp.push({A[pick.second.first][pick.second.second+1], {pick.second.first, pick.second.second+1}});
    }

    return res;
    
}

