
// Subarray with B odd numbers
// https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/



int solve(vector<int> &A, int B) {
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]%2==0)   A[i]=0;
        else A[i]=1;
    }
    
    for(int i=1; i<A.size(); i++)
    {
        A[i]+=A[i-1];
    }
    
    int res=0;
    unordered_map<int, int> mp;
    mp[0]=1;
    for(int i=0; i<A.size(); i++)
    {
        res+= mp[A[i]-B];
        mp[A[i]]++;
    }
    
    return res;
    
    
}
