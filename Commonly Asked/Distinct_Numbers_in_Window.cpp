// function to get the count of distinct numbers in a sliding window of size B
// O(n) time complexity O(B) auxiliary space


vector<int> Solution::dNums(vector<int> &A, int B) {
    
    unordered_map<int, int> mp;
    vector<int> res;
    int dist=0;
    for(int i=0; i<B; i++)
    {
        if(mp[A[i]] == 0)
        {
            dist++;
        }
        mp[A[i]]++;
    }
    res.push_back(dist);
    
    for(int i=B; i<A.size(); i++)
    {
        mp[A[i-B]]--;
        if(mp[A[i-B]] == 0)
        {
            dist--;
        }
        if(mp[A[i]] == 0)
        {
            dist++;
        }
        mp[A[i]]++;
        res.push_back(dist);
    }
    
    return res;
}
