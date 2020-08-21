// function to find the minimum number of switches you have to press to turn on all the bulbs 
// where each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.
// more at https://www.interviewbit.com/problems/bulbs/
// O(n) time complexity O(1) auxiliary space


int bulbs(vector<int> &A) {
    int count=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==0 && count%2==0)   count++;
        else if(A[i]==1 && count%2==1)  count++;
    }
    return count;
}
