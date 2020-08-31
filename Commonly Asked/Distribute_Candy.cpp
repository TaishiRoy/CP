
// function to find the minimum no. of candies required to give N children according to their ratings
// moreat https://www.interviewbit.com/problems/distribute-candy/
// O(n) time complexity O(1) auxiliary space


int candy(vector<int> &A) {
    vector<int> candy(A.size(),1);
    for(int i=1; i<A.size(); i++)
    {
        if(A[i]>A[i-1] && candy[i]<=candy[i-1])
        {
            candy[i]=1+candy[i-1];
        }
    }
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i]>A[i+1] && candy[i]<=candy[i+1])
        {
            candy[i]=1+candy[i+1];
        }
    }
    int count=0;
    for(int i=0; i<A.size(); i++)
    {
        count+=candy[i];
    }
    return count;
}

