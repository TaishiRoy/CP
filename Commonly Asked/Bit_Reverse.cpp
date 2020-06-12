// function to reverse bits of an integer in O(logn) time

unsigned int Solution::reverse(unsigned int A) {
    unsigned int rev = A;
    unsigned int count = sizeof(int)*8;
    while(A)
    {
        rev = rev << 1;
        rev = rev | (A&1);
        A >>= 1;
        count--;
    }
    rev <<= (count);
    return rev;
}
