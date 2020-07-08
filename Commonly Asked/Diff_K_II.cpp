// function to check if there exist two element in array whose difference is B
// O(nlogn) time complexity O(n) space complexity


int diffPossible(const vector<int> &A, int B) {
    
    unordered_map<int, bool> C;
    
    for(int i=0; i<A.size(); i++)
    {
        if(C.find(A[i] + B) != C.end() || C.find(A[i] - B) != C.end())
        {
            return 1;
        }
        C[A[i]]=true;
    }
    
    return 0;
}
