// container with most water solution in O(n) time and O(1) auxillary space
// get full problem explanation at https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int> &A) {
    long int currMax = 0;
    int l=0, r=A.size()-1;
    while(l<r)
    {
        currMax = currMax > (r-l)*min(A[l], A[r]) ? currMax : (r-l)*min(A[l], A[r]);
        if(A[l] < A[r]) l++;
        else    r--;
    }
    return currMax;
}
