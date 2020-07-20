
// function to find subarray to be flipped to get maximum 1's in array
// O(n) time complexity O(1) auxillary space


vector<int> Solution::flip(string A) {
    int currMin = A[0]=='0'?-1:1, minSum = currMin;
    int currStart = 0, currEnd = 0, minStart = 0, minEnd = 0;
    
    
    for(int i=1; i<A.length(); i++)
    {
        if(A[i]=='0')
        {
            if(currMin-1 <= -1)
            {
                currMin--;
                currEnd=i;
            }
            else
            {
                currMin = -1;
                currStart = i;
                currEnd = i;
            }
            
        }
        else
        {
            if(currMin+1 <= 1)
            {
                currMin++;
                currEnd=i;
            }
            else
            {
                currMin = 1;
                currStart = i;
                currEnd = i;
            }
        }
        
        if(currMin<minSum)
        {
            minSum = currMin;
            minStart = currStart;
            minEnd = currEnd;
        }
    }
    
    vector<int> res;
    if(minSum>=1)   return res;
    res.push_back(minStart+1);
    res.push_back(minEnd+1);
    
    return res;
}
