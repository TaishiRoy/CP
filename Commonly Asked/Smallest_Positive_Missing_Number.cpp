// Smallest Positive missing number

// Function to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n) { 
    
    for( int i=0; i<n; i++)
    {
        if(arr[i]<=0 || arr[i]>n)
        {
            arr[i] = n+1;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]>n)    continue;
        if(arr[i]==0)    continue;
        int temp = arr[i];
        if(arr[i]<0)
        {
            temp = -arr[i];
        }
        if(arr[temp-1] <= 0)    continue;
        arr[temp-1]= -arr[temp-1];
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)    return i+1;
    }
    
    return n+1;
    
} 
