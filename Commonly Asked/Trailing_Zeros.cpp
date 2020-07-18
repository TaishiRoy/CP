// function to calculate the no. of trailing zeros in factorial of an integer

int trailingZeroes(int A) {
    int mult = 5, zeros =0;
    while(A/mult >= 1)
    {
        zeros+= floor(A/mult);
        mult*=5;
    }
    
    return zeros;
}
