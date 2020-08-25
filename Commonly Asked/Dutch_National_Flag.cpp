
// function to solve Dutch National Flag problem
// O(n) time complexity O(1) auxiliary space


void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}


void segragate012(int arr[], int N)
{
    int low=0, mid=0, high=N-1;
    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0:
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
                break;
            }
            case 1:
            {
                mid++;
                break;
            }
            case 2:
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
    return;
}
