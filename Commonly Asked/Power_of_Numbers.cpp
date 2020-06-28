// function implementing pow (%1000000007) while taking care of overflow
// O(logN) time complexity O(logN) auxillary space

long long power(int N,int R)
{
    if(R==0)    return 1;
    if(R==1)    return (N%1000000007);
    long long sq = power(N, R/2) % 1000000007;
    sq = (sq*sq) % 1000000007;
    if(R%2==0)  return sq;
    return ((N%1000000007)*sq)%1000000007;
}
