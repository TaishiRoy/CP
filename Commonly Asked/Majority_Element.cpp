// function to find majority element in an integer array
// O(n) time complexity O(1) auxillary space


int majorityElement(const vector<int> &A) {
    
    // Part 1 : get a possible majority element O(n)
    int majEl=A[0], count=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==majEl)   count++;
        else    count--;
        
        if(count<=0)
        {
            majEl=A[i];
            count=1;
        }
    }
    
    // Part 2 : verify majority element O(n)
    count=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == majEl) count++;
        if(count>=(A.size()/2))     return majEl;
    }
    return -1;
}
