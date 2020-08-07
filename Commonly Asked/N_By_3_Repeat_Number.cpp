
// function to find the N/3 repeat number
// O(n) time complexity O(1) auxilary space


int repeatedNumber(const vector<int> &A) {

    int cand1=A[0], cand2=A[1], count1=0, count2=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==cand1) count1++;
        else if(A[i]==cand2)    count2++;
        else if(count1==0)
        {
            cand1=A[i];
            count1=1;
        }
        else if(count2==0)
        {
            cand2=A[i];
            count2=1;
        }
        else
        {
            count1--;
            count2--;
        }
        
    }
    count1=0;
    count2=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==cand1)  count1++;
        else if(A[i]==cand2)  count2++;
        if(count1>A.size()/3)    return  cand1;
        if(count2>A.size()/3)   return cand2;
    }
    
    return -1;
}

