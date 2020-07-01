// function to rearrange a given array so that Arr[i] becomes Arr[Arr[i]]
// O(n) time complexity and O(1) auxillary space


void arrange(vector<int> &A) {

    for(int i=0; i<A.size(); i++)
    {
        A[i] += (A[A[i]]%A.size())*A.size() ;
    }
    
    for(int i=0; i<A.size(); i++)
    {
        A[i] /= A.size();
    }
    return;
}
