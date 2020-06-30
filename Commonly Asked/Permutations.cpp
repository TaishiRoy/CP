// recursive function to generate all permutations of an array of integers
// O(n*n!) time complexity

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void permuteUtil(vector<int> &A, int ptr, vector<vector<int>> &out)
{
    if(ptr==A.size()-1)
    {
        out.push_back(A);
        return;
    }
    
    for(int i=ptr; i<A.size(); i++)
    {
        swap(A[ptr], A[i]);
        permuteUtil(A, ptr+1, out);
        swap(A[ptr], A[i]);
    }
    return;
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> out;
    permuteUtil(A, 0, out);
    return out;
}

