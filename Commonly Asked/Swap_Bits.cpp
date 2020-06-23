// function to return integer formed by swapping even and odd bits of an integer 
// O(1) time O(1) auxillary space

unsigned int swapBits(unsigned int n)
{
    unsigned int oddBits = n & 0xAAAAAAAA;
    oddBits >>= 1;
    
    unsigned int evenBits = n & 0x55555555;
    evenBits <<= 1;
    
    return oddBits | evenBits;
	
}
