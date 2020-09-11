
// function to return the number of subarrays with equal 0s and 1s
// O(n) time complexity O(n) auxiliary space

long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
{
    unordered_map<int, int> mp;
    for(int i=0; i<N; i++)
    {
        if(arr[i]==0)   arr[i]=-1;
    }
    mp[arr[0]]++;
    
    long long int count=0;
    for(int i=1; i<N; i++)
    {
        arr[i]+=arr[i-1];
        if(arr[i]==0)   count++;
        if(mp[arr[i]]>0)
        {
            count+=mp[arr[i]];
            mp[arr[i]]++;
        }
        else
        {
            mp[arr[i]]++;
        }
    }
    return count;
}
