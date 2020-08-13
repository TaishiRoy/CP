
// Function to find the minimum element in sorted and rotated array
// O(logn) time complexity O(1) auxiliary space

int minNumber(int arr[], int low, int high)
{
    int start=low, stop=high;
    if(arr[low]<arr[high])  return arr[low];
    while(low<=high)
    {
        if(low==high)   return arr[low];
        int mid=(low+high)/2;
        if(mid<high && arr[mid+1]<arr[mid]) return arr[mid+1];
        if(mid>0 && arr[mid]<arr[mid-1])    return arr[mid];
        if(arr[low]>arr[mid])
        {
            high=mid-1;
        }
        else    low=mid+1;
    }
    
    return arr[0];
    
}
