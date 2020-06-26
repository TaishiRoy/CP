// function to find maximum value between two elements of an array
// O(n) time complexity and O(1) space complexity


int maxAND (int arr[], int n)
{
    int patternNow = 0;
    
    for(int i=31; i>=0; i--)
    {
        int count = 0;
        for(int j=0; j<n; j++)
        {
            count+= (arr[j] & (patternNow | (1<<i))) == (patternNow | (1<<i)) ? 1 : 0;
        }
        if(count>=2)
            patternNow|= (1<<i);
    }
    
    return patternNow;
    
}
