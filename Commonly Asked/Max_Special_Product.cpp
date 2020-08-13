
// function to find max special product 
// more at https://www.interviewbit.com/problems/maxspprod/
// O(n) time complexity O(n) auxiliary space


int maxSpecialProduct(vector &A) {
    vector<int> left(A.size()), right(A.size());
    left[0] = 0;
    for(int i=1; i<A.size(); i++)
    {
        if(A[i-1] > A[i])
        {
            left[i] = i-1;
        }
        else if(A[left[i-1]] > A[i])
        {
            left[i] = left[i-1];
        }
        else
            left[i] = 0;
    }
    
    right[A.size()-1] = 0;
    for(int i=A.size()-2; i>=0; i--)
    {
        if(A[i+1] > A[i])
        {
            right[i] = i+1;
        }
        else if(A[right[i+1]] > A[i])
        {
            right[i] = right[i+1];
        }
        else
            right[i] = 0;
    }
    long long int maxProd = 0;
    for(int i=0; i<A.size(); i++)
    {
        maxProd = left[i]*right[i] > maxProd ? left[i]*right[i] : maxProd;
    }
    return maxProd%1000000007;
}

