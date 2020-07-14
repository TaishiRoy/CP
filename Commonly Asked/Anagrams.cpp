// function to find out words in an array that are anagrams
// more at https://www.interviewbit.com/problems/anagrams/
// using hashing 


vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    unordered_map<string, vector<int>> hash;
    for(int i=0; i<A.size(); i++)
    {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        hash[temp].push_back(i+1);
    }
    
    
    for(auto it=hash.begin(); it!=hash.end(); it++)
    {
        vector<int> list = it->second;
        res.push_back(list);
    }
    return res;
}
