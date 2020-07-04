// function to find next greater permutation of a sequence of integers
// O(NlogN) time complexity & O(1) auxillary space


void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


vector<int> Solution::nextPermutation(vector<int> &A) {
    int found=-1;
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i+1]>A[i])
        {
            found = i;
            break;
        }
    }
    if(found == -1)
    {
        sort(A.begin(), A.end());
        return A;
    }
    
    int nextGreat = -1;
    for(int i=found+1; i<A.size(); i++)
    {
        if(A[i] > A[found])
        {
            if(nextGreat == -1)
            {
                nextGreat = i;
            }
            else
                nextGreat = A[nextGreat] > A[i] ? i : nextGreat;
        }
    }
    swap(A[found], A[nextGreat]);
    
    sort(A.begin() + found+1, A.end());
    return A;
}
