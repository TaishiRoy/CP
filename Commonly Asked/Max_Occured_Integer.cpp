// function to find the maximum occurring integer in given ranges. If more than one such integer exits, print the smallest one.
// more at https://www.geeksforgeeks.org/maximum-occurred-integer-n-ranges/
// O(R) time complexity O(R) auxillary space (where R is the max range given)

int maxOccured(int L[], int R[], int n, int maxx){

    vector<int> arr(1000000);
    for(int i=0; i<n; i++)
    {
        arr[L[i]] +=1;
    }
    
    for(int i=0; i<n; i++)
    {
        arr[R[i]+1] -=1;
    }
    
    // prefix sum 
    for(int i=1; i<1000000; i++)
    {
        arr[i] = arr[i-1]+arr[i];
    }
    
    int maxSum=INT_MIN, ind = 0;
    for(int i=0; i<100000; i++)
    {
        if(arr[i]>maxSum)
        {
            maxSum = arr[i];
            ind = i;
        }
    }
    
    return ind;
    
}
