
// Longest Arithmetic Progression problem

// Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.
// O(n^3) time complexity O(1) auxiliary space
// NB: dp hardly gives any optimisation and needs extra space, this is brute force solution



int solve(const vector<int> &A) {
    if(A.size()<3)  return A.size();
    int res=0;
    for(int i=0; i<A.size(); i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            int diff = A[j]-A[i];
            int count=2;
            int last=A[j];
            for(int k=j+1; k<A.size(); k++)
            {
                if(A[k]-last==diff)
                {
                    count++;
                    last=A[k];
                }
            }
            res=max(count, res);
        }
    }
    return res;
}
