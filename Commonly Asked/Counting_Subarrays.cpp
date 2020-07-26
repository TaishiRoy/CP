// function to find number of subarrays in A having sum less than B (A contains non negative integers)
// O(n) time complexity O(1) auxillary space

int solve(vector<int> &A, int B) {
    int count=0, stop=0, start=0, sum=0;
    while(stop<A.size())
    {
        if(sum+A[stop]<B)
        {
            sum+=A[stop];
            count+=(stop-start+1);
            stop++;
        }
        else
        {
            sum-=A[start];
            start++;
        }
    }
    return count;
}
