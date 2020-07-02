// function to find the next greater element G[i] to right of element for every element A[i] in the array
// O(n) time complexity & O(n) auxillary space 

vector<int> nextGreater(vector<int> &A) {
    vector<int> B;
    vector<int> stk;
    int ind = A.size()-1;
    while(ind>=0)
    {
        if(stk.empty())
        {
            B.push_back(-1);
            stk.push_back(A[ind]);
            ind--;
            continue;
        }
        if(stk.back() > A[ind])
        {
            B.push_back(stk.back());
            stk.push_back(A[ind]);
            ind--;
            continue;
        }
        stk.pop_back();
    }
    
    reverse(B.begin(), B.end());
    return B;
}
