
// function to convert roman number strings to integers 
// ( IIII, XIIII is also considered a valid representation of 4, 14 and so on )


int romanToInt(string A) {
    long long int num = 0;
    for(int i=0; i<A.length()-1; i++)
    {
        if( A[i] == 'I' && 
        ((A[i+1] == 'V') || (A[i+1] == 'X') || (A[i+1] == 'L') || 
        (A[i+1] == 'C') || (A[i+1] == 'D') || (A[i+1] == 'M')) )
        {
            num-= 1;
        }
        else if( A[i] == 'V' && 
        ((A[i+1] == 'X') || (A[i+1] == 'L') || 
        (A[i+1] == 'C') || (A[i+1] == 'D') || (A[i+1] == 'M')) )
        {
            num-= 5;
        }
        else if( A[i] == 'X' && 
        ((A[i+1] == 'L') || (A[i+1] == 'C') || 
        (A[i+1] == 'D') || (A[i+1] == 'M')) )
        {
            num-= 10;
        }
        else if( A[i] == 'L' && 
        ((A[i+1] == 'C') || (A[i+1] == 'D') || (A[i+1] == 'M')) )
        {
            num-= 50;
        }
        else if( A[i] == 'C' && 
        ((A[i+1] == 'D') || (A[i+1] == 'M')) )
        {
            num-= 100;
        }
        else if( A[i] == 'D' && (A[i+1] == 'M') )
        {
            num-= 500;
        }
        else if( A[i] == 'I')
        {
            num+= 1;
        }
        else if( A[i] == 'V')
        {
            num+= 5;
        }
        else if( A[i] == 'X')
        {
            num+= 10;
        }
        else if( A[i] == 'L')
        {
            num+= 50;
        }
        else if( A[i] == 'C')
        {
            num+= 100;
        }
        else if( A[i] == 'D')
        {
            num+= 500;
        }
        else if( A[i] == 'M')
        {
            num+= 1000;
        }
    }
    
    
    if( A[A.length()-1] == 'I')
    {
        num+= 1;
    }
    else if( A[A.length()-1] == 'V')
    {
    num+= 5;
    }
    else if( A[A.length()-1] == 'X')
    {
        num+= 10;
    }
    else if( A[A.length()-1] == 'L')
    {
        num+= 50;
    }
    else if( A[A.length()-1] == 'C')
    {
        num+= 100;
    }
    else if( A[A.length()-1] == 'D')
    {
        num+= 500;
    }
    else if( A[A.length()-1] == 'M')
    {
        num+= 1000;
    }
    
    return num;
}
