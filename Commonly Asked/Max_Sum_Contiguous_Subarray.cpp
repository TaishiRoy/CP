// Function for finding the largest sum contiguous subarray from integer sequence A
// using tabulation DP

int Solution::maxSubArray(const vector<int> &A) {
    vector<int> B(A.size());
    B[0] = A[0];
    for(int i=1; i<A.size(); i++)
    {
        B[i] = A[i] > A[i] + B[i-1] ? A[i] : A[i] + B[i-1];
    }
    return *max_element(B.begin(), B.end());
}
