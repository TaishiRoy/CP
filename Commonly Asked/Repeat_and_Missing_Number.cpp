// function to find repeat and missing number in array of integers
// more at https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// O(n) time complexity O(1) auxiliary space

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xorres = A[0]^1;
    vector<int> res(2);
    for(int i=1; i<A.size(); i++)
    {
        xorres ^= A[i];
        xorres ^= i+1;
    }
    
    int rightset = xorres & ~(xorres-1);
    
    int zero=0, one=0; 
    for(int i=0; i<A.size(); i++)
    {
        if(!(rightset & A[i]))
        {
            zero^=A[i];
        }
        else
        {
            one^=A[i];
        }
    }
    
    for(int i=1; i<=A.size(); i++)
    {
        if(!(rightset & i))
        {
            zero^=i;
        }
        else
        {
            one^=i;
        }
    }
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==one)
        {
            res[0]=one;
            res[1]=zero;
            break;
        }
        else if(A[i]==zero)
        {
            res[0]=zero;
            res[1]=one;
            break;
        }
    }
    
    return res;
}
