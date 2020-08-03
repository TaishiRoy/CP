
// function to find if given number is power of 2 or not.
// O(n^2) time complexity (where n=length of string) O(1) auxiliary space


int power(string A) {
    if(A.length()==1 && A[0]=='1')  return 0;
    string aux;
    int num=0;
    while(A.length()!=1 || A[0]!='1')
    {
        if(int(A[A.length()-1]-'0')%2 != 0) return 0;
        for(int i=0; i<A.length(); i++)
        {
            num*=10;
            num+=A[i]-'0';
            if(num<2)
            {
                if(i!=0)    aux+='0';
                continue;
            }
            int rem = num%2;
            aux+=(num/2+'0');
            num=rem;
            
        }
        
            A=aux;
            aux="";

    }
    
    return 1;
    
}
