
// function to allocate A books to B number of students so that maximum number of pages alloted to a student is minimum.
// more at https://www.interviewbit.com/problems/allocate-books/
// O(nlogn) time complexity O(10 auxillary space


int books(vector<int> &A, int B) {
    
    if(B>A.size())  return -1;
    int minPage=0, maxPage=0;
    for(int i=0; i<A.size(); i++)
    {
        maxPage+=A[i];
    }
    int mid, validAns=-1;
    while(minPage<=maxPage)
    {
        mid = (minPage+maxPage)/2;
        // try to form a situation where the maximum no of pages read by a student is mid
        int currSum=0, stdnt=1;
        bool invalid=false;
        for(int i=0; i<A.size(); i++)
        {
            if(A[i] > mid)
            {
                invalid=true;
                break;
            }
            if(currSum+A[i] > mid)
            {
                stdnt++;
                if(stdnt>B) 
                {
                    invalid=true;
                    break;
                }
                currSum = A[i];
            }
            else
            {
                currSum+=A[i];
            }
        }
        if(invalid)
        {
            minPage=mid+1;
        }
        else
        {
            validAns = mid;
            maxPage=mid-1;
        }
    }
    
    return validAns;
   
}
