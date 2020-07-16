
// function to check if there exist two element in array whose difference is B
// more at https://www.interviewbit.com/problems/pair-with-given-difference/
// same problem statement as Diff-K-II but with two pointer solution
// O(nlogn) time complexity O(1) auxillary space

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int ptrA=0,ptrB=0;
    while(ptrA<A.size() && ptrB<A.size())
    {
        int k = A[ptrA] - A[ptrB];
        if((k==B || k==-B) && (ptrA!=ptrB))
        {
            return 1;
        }
        if(k<B)
            ptrA++;
        else
            ptrB++;
    }
    return 0;
}
