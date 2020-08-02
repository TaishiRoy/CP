
// function to return the index of any peak element present in the array
// O(n) time complexity O(1) auxiliary space


int peakElement(int arr[], int n)
{
   int low=0, high=n-1;
   while(low<=high)
   {
       int mid=(low+high)/2;
       if((mid==0 || arr[mid]>=arr[mid-1])  && (mid==n-1 || arr[mid]>=arr[mid+1]))
       {
           return mid;
       }
       if(mid>0 && arr[mid-1]>=arr[mid])
       {
           high=mid-1;
       }
       else
       {
           low=mid+1;
       }
   }
   return 0;
}
