
// function to generate all combinations aCb


void util(vector<vector<int>> &res, vector<int> str, int len, int curr, int A, int B)
{
    if(str.size()==B)
    {
        res.push_back(str);
        return;
    }
    if(curr==A)
    {
        return;
    }
    while(len<B && curr<A)
    {
        str.push_back(curr+1);
        curr++;
        util(res, str, len+1, curr, A, B);
        str.pop_back();
    }
    
    return;
}


vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<vector<int>> res;
    vector<int> str;
    util(res, str, 0, 0, A, B);
    return res;
}
