

// Array 3 Pointers
// more at https://www.interviewbit.com/problems/array-3-pointers/
// You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
// Find i, j, k such that :
// max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
// Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

// O(n) time complexity O(1) space complexity

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int a=0, b=0, c=0;
    int res = INT_MAX;
    while(a<A.size() && b<B.size() && c<C.size())
    {
        res = min( res, 
            ( max(A[a], max(B[b], C[c])) - min(A[a], min(B[b], C[c]))) );
        if(A[a]==min(A[a], min(B[b], C[c])))    a++;
        else if(B[b]==min(A[a], min(B[b], C[c])))    b++;
        else c++;
    }
    return res;
}
