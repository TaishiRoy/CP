// function to find the trapped water in between buildings
// more at https://www.geeksforgeeks.org/trapping-rain-water/
// O(n) time complexity O(n) auxiliary space

int trappingWater(int arr[], int n){

    int l[n], r[n];
    l[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        l[i]=max(l[i-1], arr[i]);
    }
    r[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        r[i] = max(r[i+1], arr[i]);
    }
    int res=0;
    for(int i=0; i<n; i++)
    {
        res+=min(l[i], r[i]) - arr[i];
    }
    return res;
}
