// function to find the length of the last word in a sentence
// O(n) time complexity O(1) auxillary space

int lengthOfLastWord(const string A) {
    int pos = -1, flag =0;
    int len = A.length();
    for(int i=A.length()-1; i>=0; i--)
    {
        if(A[i]==' ')
        {
            len--;
        }
        else
        {
            break;
        }
    }
    if(len==0)  return 0;
    for(int i=0; i<len; i++)
    {
        if(A[i]!=' ')
        {
            flag = 1;
        }
        if(A[i]==' ')
        {
            pos=i;
        }
    }
    if((pos==-1 && flag==0) || pos==A.length()-1)    return 0;
    if(pos==-1 && flag==1)
    {
        return len;
    }
    return len-pos-1;
}
