
// function to calculate maximum of sliding window of length B in an array
// O(n) time complexity O(B) auxiliary space


vector<int> slidingMaximum(const vector<int> &A, int B) {
    vector<int> C;
    deque<int> D;
    
    if(B>A.size())
    {
        C.push_back(*max_element(A.begin(), A.end()));
        return C;
    }
    for(int i=0; i<B; i++)
    {
        while( !D.empty() && A[i] > D.back())
        {
            D.pop_back();
        }
        D.push_back(A[i]);
    }
    
    C.push_back(D.front());
    
    for(int i=B; i<A.size(); i++)
    {
        if(A[i-B] == D.front())
        {
            D.pop_front();
        }
        while( !D.empty() && A[i] > D.back())
        {
            D.pop_back();
        }
        D.push_back(A[i]);
        C.push_back(D.front());
    }
    
    return C;
    
}
