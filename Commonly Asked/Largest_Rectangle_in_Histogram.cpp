
// function that returns the area of the largest rectangle in histogram
// O(n) time complexity & O(n) auxillary space


int Solution::largestRectangleArea(vector<int> &A) {
    
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
