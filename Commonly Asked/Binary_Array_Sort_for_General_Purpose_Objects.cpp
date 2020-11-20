
// Sorting a binary array (applicable for general purpose objects)

// O(n) time complexity O(1) space complexity



// Function to sort the array A[]
// A[]: input array
// N: input array
void binSort(int A[], int N)
{
   //Your code here
   int low=-1;
   for(int i=0; i<N; i++)
   {
       if(A[i]==0)
       {
           low++;
           swap(A[i], A[low]);
       }
   }
   return;
}
