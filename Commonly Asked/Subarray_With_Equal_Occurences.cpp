
// function to find the number of subarrays in which the number of occurrences of B is equal to number of occurrences of C
// more at https://www.interviewbit.com/problems/subarray-with-equal-occurences/
// O(n) time complexity O(n) auxuliary space


int solve(vector<int> &A, int B, int C) {
    vector<int> countB(A.size()), countC(A.size()), diff(A.size());
    if(A[0]==B) countB[0]=1;
    if(A[0]==C) countC[0]=1;
    for(int i=1; i<A.size(); i++)
    {
        countB[i]=countB[i-1];
        if(A[i]==B) countB[i]++;
        countC[i]=countC[i-1];
        if(A[i]==C) countC[i]++;
    }
    
    for(int i=0; i<A.size(); i++)
    {
        diff[i]=countB[i]-countC[i];
    }
    
    unordered_map<int, int> mp;
    for(int i=0; i<A.size(); i++)
    {
        mp[diff[i]]++;
    }
    int res=mp[0];
    for(auto i=mp.begin(); i!=mp.end(); i++ )
    {
        res+= (i->second)*((i->second)-1)/2;
    }
    return res;
}
