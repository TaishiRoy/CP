
// function to find the first repeating element
// more at https://www.interviewbit.com/problems/first-repeating-element/
// O(n) time complexity O(n) auxiliary space


int solve(vector<int> &A) {
    unordered_map<int, int> mp;
    int res=INT_MAX;
    for(int i=0; i<A.size(); i++)
    {
        if(mp[A[i]])
        {
            res=min(res, mp[A[i]]);
        }
        else
        {
            mp[A[i]]=i+1;
        }
    }
    if(res==INT_MAX)    return -1;
    return A[res-1];
}

