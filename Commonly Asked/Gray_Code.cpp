// function to generate the sequence of gray codes for integers with n bits
// more info at https://www.interviewbit.com/problems/gray-code/
// O(2^n) time complexity and O(2^n) auxillary space

void util(vector<int> &res, int bit, int& num)
{
    if(bit==0)
    {
        res.push_back(num);
        return;
    }
    
    
    util(res, bit-1 , num);
    num^=(1<<bit-1);
    util(res, bit-1 , num);
    return;
}


vector<int> grayCode(int A) {

    vector<int> res;
    int num =0;
    util(res, A, num);
    return res;
}
