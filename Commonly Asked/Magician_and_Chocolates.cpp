

// Magician and Chocolates
// more at https://www.interviewbit.com/problems/magician-and-chocolates/
// O(n + Alogn) time complexity O(1) auxiliary space

int Solution::nchoc(int A, vector<int> &B) {
    
    make_heap(B.begin(), B.end());
    long long int res=0;
    for(int i=0; i<A; i++)
    {
        long long int temp=B.front();
        pop_heap(B.begin(), B.end());
        B.pop_back();
        B.push_back(floor(temp/2));
        push_heap(B.begin(), B.end());
        res+=temp;
    }
    return res%1000000007;
}
