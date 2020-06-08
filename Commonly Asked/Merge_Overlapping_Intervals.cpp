// fuction for merge overlapping intervals problem in O(nLogn)

/**
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool customCompare(Interval a, Interval b)
{
    return (a.start < b.start);
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {

    sort(A.begin(), A.end(), customCompare);
    vector<Interval> B;
    B.push_back(A[0]);
    for(int i=1; i<A.size(); i++)
    {
        if(A[i].start <= B.back().end)
        {
            B.back().end = A[i].end > B.back().end ? A[i].end : B.back().end ;
        }
        else
        {
            B.push_back(A[i]);
        }
    }
    return B;
}
