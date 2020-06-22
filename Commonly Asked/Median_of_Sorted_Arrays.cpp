// function to find median of the sorted array formed by merging two sorted arrays
// O(m+n) time complexity and O(1) auxillary space

// goal is to find a partition between two arrays such that all elements in left half is less than right half


double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(A.size() > B.size()) return findMedianSortedArrays(B,A);
    int partX,partY, start=0, end=A.size(), len=(A.size()+B.size());
    
    while(start <= end)
    {
        partX = (start+end)/2;
        partY = (len+1)/2 - partX;
        int maxLeftX = partX-1 < 0 ? INT_MIN : A[partX-1];
        int maxLeftY = partY-1 < 0 ? INT_MIN : B[partY-1];
        int minRightX = partX >= A.size() ? INT_MAX : A[partX];
        int minRightY = partY >= B.size() ? INT_MAX : B[partY];
        if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if(len%2 == 0)   return double((max(maxLeftX , maxLeftY) + min(minRightX , minRightY))*1.0/2);
            else return double(max(maxLeftX, maxLeftY));
        }
        
        if(maxLeftX > minRightY)
        {
            end = partX - 1;
        }
        else
            start = partX + 1;
            
    }
    
    return -1;
    
    
}
