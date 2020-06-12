// function implementing atoi ( ASCII character to integer )


#define ll long long

// to check if any char is whitespace
bool isSpace(unsigned char c)
{
    return (c==' ')||(c=='\n')||(c=='\t')||(c=='\r')||(c=='\v')||(c=='\f');
}

int Solution::atoi(const string A) {
    string out = A; //automatically ignores preceding whitespaces
    
    for(ll i=0; i<out.length(); i++)
    {
        if(isSpace(out[i]))
        {
            out = out.substr(0, i);
            break;
        }
    }
    
    // takes in to consideration signed integer strings
    if( ((out[0] == '+') || (out[0] == '-')) && ((int(out[1]) > int('9')) || (int(out[1]) < int('0'))))
        return 0;
        
        
    if(out[0] == '+')
        out = out.substr(1, out.length()-1);
    
    for(ll i=0; i<out.length(); i++)
    {
        if(i==0 && out[i]=='-') continue;
        if((int(out[i]) > int('9')) || (int(out[i]) < int('0')))
        {
            out = out.substr(0, i);
            break;
        }
    }
    
    
    
    ll res =0;
    bool neg= false;
    if(out[0] == '-')   neg = true;
    
   
    for(ll i=0; i<out.length();i++)
    {
        if(i==0 && neg) continue;
        res*=10;
        if(res>INT_MAX)
        {
            res=INT_MAX;
            break;
        }
        res+=int(out[i]) - int('0');
        if(res>INT_MAX)
        {
            res=INT_MAX;
            break;
        }
    }
    if(res>=INT_MAX && neg)   return INT_MIN;
    if(res>=INT_MAX)   res=INT_MAX;
    if(neg) res*=-1;
    return res;
}
