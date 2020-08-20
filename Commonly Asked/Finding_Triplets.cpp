
// find if there exists a triplet with 0 sum
// O(n^2) time complexity O(1) auxiliary space


bool findTriplets(int arr[], int n)
{ 
    sort(arr, arr+n);
    
    for(int i=0; i<n; i++)
    {
        int l=0, r=n-1;
        while(l<r)
        {
            if(l==i)
            {
                l++;
                continue;
            }
            if(r==i)
            {
                r--;
                continue;
            }
            if(arr[i]+arr[l]+arr[r]==0) return true;
            if(arr[i]+arr[l]+arr[r]>0)  r--;
            else l++;
        }
    }
    return false;
    
}
