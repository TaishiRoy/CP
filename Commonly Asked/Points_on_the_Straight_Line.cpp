

// Points on the Straight Line

// O(n^2) time complexity

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()<=2) return A.size();
    unordered_map<double, int> mp;
    int maxRes = 2;
    for(int i=0; i<A.size(); i++)
    {
        mp.clear();
        int currCount = 0,vert = 0, overlap = 0;
        for(int j=i+1; j<A.size(); j++)
        {
            if(A[i]==A[j] && B[i]==B[j])    overlap++;
            else if(A[i]-A[j] == 0) vert++;
            else 
            {
                mp[double((B[i]-B[j]))/(A[i]-A[j])]++;
                currCount = max(currCount, mp[double((B[i]-B[j]))/(A[i]-A[j])]);
            }
            currCount = max(currCount, vert);
        }
        maxRes = max(currCount+overlap+1, maxRes);
        
    }
    return maxRes;
}

