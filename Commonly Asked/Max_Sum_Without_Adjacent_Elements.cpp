
// function to get Max Sum without Adjacent Elements
// O(n) time complexity O(1) auxiliary space


int adjacent(vector<vector<int> > &A) {
    int incl=max(A[0][0], A[1][0]);
    int excl=0;
    for(int i=1; i<A[0].size(); i++)
    {
        int excltemp = max(incl, excl);
        incl = excl+max(A[0][i], A[1][i]);
        excl=excltemp;
    }
    return max(incl, excl);
}

