
// function to implement fractional knapsack using dp
// O(nlogn) time complexity O(1) auxiliary space

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool myComp(Item a, Item b)
{
    return (((a.value*1.0)/a.weight)>((b.value*1.0)/b.weight));
}

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, myComp);
    double res=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i].weight<W)
        {
            res+=arr[i].value;
            W-=arr[i].weight;
        }
        else
        {
            res+=(arr[i].value)*((W*1.0)/arr[i].weight);
            return res;
        }
    }
    return res;
}
