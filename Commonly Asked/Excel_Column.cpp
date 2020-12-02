
// Excel Column Title
// O(n) time complexity O(1) space complexity

string Solution::convertToTitle(int A) {
    string out;
    while(A>0)
    {
        out+=(A-1)%(26)+'A';
        A=(A-1)/26;
    }
    reverse(out.begin(), out.end());
    return out;
}
