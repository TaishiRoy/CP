// function to calculate maximum circular subarray sum
// O(n) time complexity O(1) auxiliary space

int kadane(int arr[], int num)
{
    int maxSum=arr[0], curr=arr[0];
    for(int i=1; i<num; i++)
    {
        curr=max(curr+arr[i], arr[i]);
        maxSum=max(maxSum, curr);
    }
    return maxSum;
}

int minkadane(int arr[], int num)
{
    int sum=0;
    for(int i=0; i<num; i++)
    {
        sum+=arr[i];
    }
    for(int i=0; i<num; i++)
    {
        arr[i]=-arr[i];
    }
    
    return sum+kadane(arr, num); 
}


int circularSubarraySum(int arr[], int num){

    if(num==1)  return arr[0];
    int a=kadane(arr, num);
    if(a<0) return a;
    int b=minkadane(arr, num);
    return max(a,b);
}
