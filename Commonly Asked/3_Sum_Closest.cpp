// function to calculate the closest sum of three elements to a given target 
// Problem Statement :Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. Assume that there will only be one solution
// O(N^2) time complexity O(1) auxillary space


int threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    long int closest = 1000000000;
    for(int i=0; i<A.size(); i++)
    {
        int ptrLow = 0;
        int ptrHigh = A.size()-1;
        while(1)
        {
            if(ptrLow >= ptrHigh)   break;
            if(ptrLow==i)
            {
                ptrLow++;
                continue;
            }
            if(ptrHigh==i)
            {
                ptrHigh--;
                continue;
            }
            
            if(A[ptrLow] + A[ptrHigh] + A[i] == B)
            {
                return B;
            }
            
            if(abs(B-(A[ptrLow] + A[ptrHigh] + A[i])) < abs(B-closest))
            {
                closest = (A[ptrLow] + A[ptrHigh] + A[i]);
            }
            
            if( (A[ptrLow] + A[ptrHigh] + A[i]) > B )
            {
                ptrHigh--;
            }
            else
            {
                ptrLow++;
            }
            
        }
    }
    
    return closest;
}
