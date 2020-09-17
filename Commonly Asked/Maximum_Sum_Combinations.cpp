
// function to return the maximum C valid sum combinations from all the possible sum combinations of two equally sized 1-D arrays A, B containing N integers each.
// A sum combination is made by adding one element from array A and another element of array B.
// more at https://www.interviewbit.com/problems/maximum-sum-combinations/
// O(nlogn) time complexity O(n) auxiliary space


vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    vector<int> res;
    set<pair<int, int>> st;
    priority_queue<pair<int, pair<int, int>>> hp;
    hp.push({A[0]+B[0], {0, 0}});
    st.insert({ 0, 0});
    for(int i=0; i<C; i++)
    {
        res.push_back(hp.top().first);
        auto t= hp.top();
        hp.pop();
        pair<int, int> a1(t.second.first+1, t.second.second);
        pair<int, pair<int, int>> a2(A[a1.first]+B[a1.second], a1);
        if(st.count(a1)==0)
        {
            hp.push(a2);
            st.insert(a1);
        }
        
        
        pair<int, int> b1(t.second.first, t.second.second+1);
        pair<int, pair<int, int>> b2(A[b1.first]+B[b1.second], b1);
        if(st.count(b1)==0)
        {
            hp.push(b2);
            st.insert(b1);
        }
    }
    return res;
}
