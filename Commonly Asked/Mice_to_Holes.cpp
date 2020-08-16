
// function to optimize assigning mice to holes
// more at https://www.interviewbit.com/problems/assign-mice-to-holes/
// O(nlogn) time complexity O(1) auxiliary space


int mice(vector<int> &A, vector<int> &B) {
    int res=0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<A.size(); i++)
    {
        res=max(res, abs(A[i]-B[i]));
    }
    return res;
}
