
// function for Subarray with 0 sum 
// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> st;
    st.insert(arr[0]);
    if(arr[0]==0)   return true;
    for(int i=1; i<n; i++)
    {
        arr[i]=arr[i-1]+arr[i];
        if(st.count(arr[i])==1) return true;
        if(arr[i]==0)   return true;
        st.insert(arr[i]);
    }
    return false;
    
}
