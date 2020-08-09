// function to find the count of element pairs where A[i]>A[j] and i<j
// O(nlogn) time complexity O(n) auxiliary space


int countMerge(vector<int> &A, int l, int mid, int r)
{
    vector<int> left(mid-l+1), right(r-mid);
    for(int i=0; i<left.size(); i++)
    {
        left[i]=A[l+i];
    }
    for(int i=0; i<right.size(); i++)
    {
        right[i] = A[i+mid+1];
    }
    int x=0, y=0, curr=l, res=0;
    while(x<left.size() && y<right.size())
    {
        if(left[x]<=right[y])
        {
            A[curr++] = left[x++];
        }
        else
        {
            A[curr++] = right[y++];
            res+= (left.size()-x);
        }
    }
    while(x<left.size())
    {
        A[curr++] = left[x++];
    }
    while(y<right.size())
    {
        A[curr++] = right[y++];
    }
    return res;
}

int countInv(vector<int> &A, int l, int r)
{
    int res=0;
    if(l<r)
    {
        int mid=l+((r-l)/2);
        res+=countInv(A, l, mid);
        res+=countInv(A, mid+1, r);
        res+=countMerge(A, l, mid, r);
    }
    return res;
    
}

int countInversions(vector<int> &A) {
    return countInv(A, 0, A.size()-1);
}
