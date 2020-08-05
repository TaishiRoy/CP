// function to create a Pascal's triangle
// O(n^2) time complexity O(1) auxiliary space

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    if(A==0)    return res;
    vector<int> first;
    first.push_back(1);
    res.push_back(first);
    for(int i=1; i<A; i++)
    {
        vector<int> row(i+1);
        for(int j=0; j<i+1; j++)
        {
            if(j==0 || j==i)    row[j]=1;
            else
            {
                row[j]=res[i-1][j-1] + res[i-1][j];
            }
        }
        res.push_back(row);
    }
    return res;
}

