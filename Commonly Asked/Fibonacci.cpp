// Fibonacci
// O(n) time complexity O(1) space complexity

class Solution {
public:
    int fib(int N) {
        int a=0, b=1;
        if(N==0)    return a;
        if(N==1)    return b;
        for(int i=2; i<=N; i++)
        {
            int temp = b;
            b+= a;
            a = temp;
        }
        return b;
    }
};

