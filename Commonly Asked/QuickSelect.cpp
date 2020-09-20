

// function to find the kth largest element
// O(n^2) time complexity but O(n) for randomised 

int partition(int *arr, int low, int high)
{
    swap(arr[high], arr[low+rand()%(high-low+1)]);
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


// if you want to use hoares partition
int hoares(int *arr, int low, int high)
{
    int pivot=arr[low];
    int i=low-1, j=high+1;
    while(1)
    {
        do
        {
            i++;
        }
        while(arr[i]<pivot);
        do
        {
            j--;
        }
        while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[j], arr[i]);
    }
}
int kthSmallest(int arr[], int n, int k){
    
    int low=0, high=n-1;
    while(low<=high)
    {
        int part = partition(arr, low, high);
        if(part+1==k)  return arr[part];
        if(part+1<k)    
        {
            low=part+1;
        }
        else
        {
            high=part-1;
        }
    }
    return -1;
    
}
