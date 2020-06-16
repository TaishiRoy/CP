// function to calculate length after removing duplicates from a sorted array
// using O(1) auxillary space and O(n) time

int removeDuplicates(vector<int> &A) {
    int start =0, len=A.size();
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] != A[start])
        {
            len -=  i-start-1;
            start = i;
            continue;
        }
        if(i==A.size()-1)
        {
            len-= i-start ;
        }
    }
    start =0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] != A[start])
        {
            start++;
            A[start] = A[i];
        }
    }
    A.resize(len);
    return len;
}
