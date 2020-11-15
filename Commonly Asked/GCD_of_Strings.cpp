
// Greatest Common Divisor of Strings
// For two strings s and t, we say "t divides s" if and only if s = t + ... + t  (t concatenated with itself 1 or more times)
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// O(n^2) time complexity

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1=="" && str2=="")    return "";
        if(str1=="")    return str2;
        if(str2=="")    return str1;
        if(str1.length() >= str2.length() && str1.substr(0, str2.length())==str2)
        {
            return gcdOfStrings(str1.substr(str2.length(), str1.length()-str2.length()), str2);
        }
        else if(str2.length() >= str1.length() && str2.substr(0, str1.length())==str1)
            return gcdOfStrings(str2.substr(str1.length(), str2.length()-str1.length()), str1);
        else    return "";
    }
};
