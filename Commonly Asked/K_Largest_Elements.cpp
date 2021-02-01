
// function to get the k largest elements in an array using priority queue
// O(k + (n-k)Logk + kLogk) time complexity O(k) auxiliary space


vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    sort(res.begin(), res.end(), greater<int>());
    return res;
}

// K largest elements
// (using vector as heap with make_heap(), push_heap(), pop_heap())
// O(k + (n-k)Logk + kLogk) 


vector<int> kLargest2(int arr[], int n, int k)
{
    // code here
    vector<int> pq;
    for(int i=0; i<k; i++)
    {
        pq.push_back(arr[i]);
        push_heap(pq.begin(), pq.end(), greater<int>());
    }
    for(int i=k; i<n; i++)
    {
        if(arr[i]>pq.front())
        {
            pop_heap(pq.begin(),pq.end(), greater<int>());
            pq.pop_back();
            pq.push_back(arr[i]);
            push_heap(pq.begin(), pq.end(), greater<int>());
        }
    }
    sort(pq.begin(), pq.end(), greater<int>());
    return pq;
}

