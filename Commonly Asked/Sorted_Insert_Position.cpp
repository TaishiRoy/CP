
// function to return the index if the target is found in a sorted array If not, return the index where it would be if it were inserted in order.
// O(logn) time complexity O(1) auxiliary space


int searchInsert(vector<int> &A, int B) {

    int low=0, high=A.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid]==B)   return mid;
        if((A[mid-1]<B||mid==0) && A[mid]>B)   return mid;
        if(A[mid]<B && (A[mid+1]>B||mid==A.size()-1))   return mid+1;
        if(A[mid]<B)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return A.size();
}
