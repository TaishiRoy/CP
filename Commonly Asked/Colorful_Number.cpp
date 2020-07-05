// function to check if a number is colorful or not using hashing
// problem details at https://www.interviewbit.com/problems/colorful-number/

int colorful(int A) {
    
    vector<int> B;
    while(A!=0)
    {
        B.push_back(A%10);
        A/=10;
    }
    
    unordered_map<int, int> hash;
    
    for(int i=0; i<B.size(); i++)
    {
        long int prod = 1;
        for( int j=i; j<B.size(); j++)
        {
            prod *= B[j];
            if(hash.find(prod) == hash.end())
            {
                hash[prod]++;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
