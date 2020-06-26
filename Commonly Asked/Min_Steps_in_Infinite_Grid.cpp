// function to calculate minimum steps required to cover all given points in sequence in an infinite 2D grid where travelling in eight directions in each step is allowed
// O(n) time complexity O(1) auxillary space

int coverPoints(vector<int> &A, vector<int> &B) {
    int stepCount = 0;
    for(int i=1; i<A.size(); i++)
    {
        stepCount+= max(abs(A[i] - A[i-1]), abs(B[i]-B[i-1]));
    }
    return stepCount;
}
