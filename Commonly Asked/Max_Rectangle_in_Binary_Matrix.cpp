
// function to find the largest rectangle containing all ones and return its area in a binary matrix
// O(R*C) time complexity O(C) space


int largestRec(vector<int> &A)
{
    vector<int> stk;
    int i=0, area = 0, maxArea = -1, top=0;
    while(1)
    {
        if(i>=A.size() && stk.empty())  break;
        if(i<A.size() && stk.empty())
        {
            stk.push_back(i);
            i++;
            continue;
        }
        if(A[i] < A[stk.back()] || i>=A.size())
        {
            top = stk.back();
            stk.pop_back();
            if(stk.empty())
            {
                area = A[top] * i;
                maxArea = max(maxArea, area);
            }
            else
            {
                area = A[top] * (i - stk.back() - 1);
                maxArea = max(maxArea, area);
            }
        }
        else
        {
            stk.push_back(i);
            i++;
        }
    }
    return maxArea;
}


int maximalRectangle(vector<vector<int> > &A) {
    int res=0;
    res = max(res, largestRec(A[0]));
    for(int i=1; i<A.size(); i++)
    {
        for(int j=0; j<A[i].size(); j++)
        {
           if(A[i][j]!=0) A[i][j] += A[i-1][j];
           res = max(res, largestRec(A[i]));
        }
    }
    
    return res;
    
    
}
