
// function to find the longest substring without repeat
// more at https://www.interviewbit.com/problems/longest-substring-without-repeat/

int lengthOfLongestSubstring(string A) {
    unordered_map<char, bool> mp;
    int start=0, stop=0, currMax = INT_MIN;
    while(stop<A.length())
    {
        
        if(mp[A[stop]] == false)
        {
            mp[A[stop]] = true;
            currMax = max(currMax, stop-start+1);
            stop++;
        }
        else
        {
            while(A[start] != A[stop])
            {
                mp[A[start]] = false;
                start++;
            }
            start++;
            currMax = max(currMax, stop-start+1);
            stop++;
        }
    }
    return currMax;
}
