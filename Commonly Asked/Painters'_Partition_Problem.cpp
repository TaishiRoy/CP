
// function to solve painters' partition problem
// more at https://www.interviewbit.com/problems/painters-partition-problem/
// O(nlogn) time complexity O(1) auxillary space 


int isValid(int A, vector<int> &C, long long mid)
{
    int count = 1;
    long long currSum = 0, maxCurr=0;
    for(int i=0; i<C.size(); i++)
    {
        if(currSum+C[i] <= mid)
        {
            currSum+=C[i];
        }
        else
        {
            if(C[i]>mid)
            {
                return -1;
            }
            count++;
            if(count>A) return -1;
            maxCurr = max(maxCurr, currSum);
            currSum=C[i];
        }
    }
    maxCurr = max(maxCurr, currSum);
    if(count>A) return -1;
    else return 1;
}


int paint(int A, int B, vector<int> &C) {
    if(A>C.size())
    {
        long long res = *max_element(C.begin(), C.end())%10000003;
        res*=B%10000003;
        res%=10000003;
        return int(res);
    }
    long long sumAll = 0;
    for(int i=0; i<C.size(); i++)
    {
        sumAll+=C[i];
    }
    long long l=0, r=sumAll;
    long long mid;
    long long valid = 0;
    while(l<=r)
    {
        
        mid = (l+r)/2;
        int poss=isValid(A, C, mid);
        if(poss==0)
        {
            long long res = mid%10000003;
            res*=B%10000003;
            res%=10000003;
            return int(res);
        }
        if(poss<0)
        {
            l=mid+1;
        }
        else
        {
            valid = mid;
            r=mid-1;
        }
        
    }
    long long res = valid%10000003;
    res*=B%10000003;
    res%=10000003;
    return int(res);
}

