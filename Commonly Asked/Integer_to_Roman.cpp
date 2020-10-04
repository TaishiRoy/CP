
// function to convert integer A to a roman numeral
// 1 <= A <= 3999
// O(logn) time complexity 

string intToRoman(int A) {
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hunds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thous[] = {"", "M", "MM", "MMM"};
    
    return thous[A/1000] + hunds[(A%1000)/100] + tens[(A%100)/10] + ones[(A%10)];

}
