// function to merge two sorted arrays into a third sorted array
// O(m+n) time complexity O(m+n) space complexity


void merge(vector<int> &A, vector<int> &B) {

    vector<int> C;
    
    int ptrA = 0, ptrB = 0;
    
    while(!(ptrA >= A.size() && ptrB >= B.size()))
    {
        if( ptrA >= A.size())
        {
            C.push_back(B[ptrB]);
            ptrB++;
            continue;
        }
        if( ptrB >= B.size())
        {
            C.push_back(A[ptrA]);
            ptrA++;
            continue;
        }
        if(A[ptrA] < B[ptrB])
        {
            C.push_back(A[ptrA]);
            ptrA++;
            continue;
        }
        if(B[ptrB] < A[ptrA])
        {
            C.push_back(B[ptrB]);
            ptrB++;
            continue;
        }
        if(A[ptrA] == B[ptrB])
        {
            C.push_back(A[ptrA]);
            C.push_back(B[ptrB]);
            ptrA++;
            ptrB++;
            continue;
        }
        
        
    }
    
    A = C;
}
