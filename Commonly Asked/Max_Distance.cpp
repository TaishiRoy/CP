// function to find the maximum of j - i subjected to the constraint of A[i] <= A[j].
// O(n) time complexity O(n) auxillary space


int maximumGap(const vector<int> &A) {
    vector<int> minL(A.size()), maxR(A.size());
    minL[0] = A[0];
    for(int i=1; i<A.size(); i++)
    {
        minL[i] = min(minL[i-1], A[i]);
    }
    maxR[A.size()-1]=A[A.size()-1];
    for(int i=A.size()-2; i>=0; i--)
    {
        maxR[i] = max(maxR[i+1], A[i]);
    }
    int dist=0;
    for(int l=0,r=0; l<A.size(), r<A.size(); )
    {
        if(minL[l] <= maxR[r])
        {
            dist=max(dist, r-l);
            r++;
        }
        else
        {
            l++;
        }
    }
    
    return dist;
}
