// Remove Duplicates from Sorted Array II

// Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
// O(n) time complexity O(1) auxiliary space


int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int curr = A[0], count=1, ptr=0;
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]==curr)  count++;
        else
        {
            curr=A[i];
            count=1;
        }
        if(count<=2)
        {
            ptr++;
            A[ptr]=curr;
        }
    }
    return ptr+1;
}

