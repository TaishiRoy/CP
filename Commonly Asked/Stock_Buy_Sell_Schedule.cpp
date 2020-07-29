// function to find the buy sell schedule for maximum profit
// O(n) time complexity O(1) auxillary space

void stockBuySell(int price[], int n)
{
    int maxProf = 0, start=0, stop=0, prof=0;
    
    for(int i=1; i<n; i++)
    {
        if(price[i]==price[i-1])
        {
            if(start==stop) start++;
            stop++;
        }
        else if(price[i]>price[i-1])
        {
            maxProf+=(price[i]-price[i-1]);
            prof=1;
            stop++;
        }
        else
        {
            if(start!=stop && maxProf!=0) cout << "(" << start << " " << stop << ") ";
            start=i;
            stop=i;
            maxProf=0;
        }
    }
    if(prof==0) cout << "No Profit ";
    else if(start!=stop) cout << "(" << start << " " << stop << ") ";
    return;
    
}
