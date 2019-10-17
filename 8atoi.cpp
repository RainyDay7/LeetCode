class Solution {
public:
    int myAtoi(string str) {
        // if (str=="" || str[0]) return 0;
        // string blanks("\f\v\r\t\n ");
        // str.erase(0,str.find_first_not_of(blanks));
        //INT_MAX C++int的最大值  INT_MINC++的最小值 
        int sign = 1,i=0;
        
        str.erase(0,str.find_first_not_of(" "));//除去前面的所有空格 
        if (str=="") return 0;
        if (str[i]== '-' || str[i] == '+')
        sign = str[i++] == '-' ? -1 : 1;
        
        int len = str.length();
        int value = 0;
        while(isdigit(str[i]) && i<len){
            // 如果base > MAX_VALUE/10，那么base*10 + new_value > base*10 > MAX_VALUE，这种情况下就会发生溢出。        
            // 若base == INT_MAX/10，而且new_value = str.charAt(i++) - '0'`大于`7`，也会发生溢出。因为MAX_VALUE = 2147483647        
            if (value > INT_MAX/10 || (value == INT_MAX / 10 && str[i] - '0' > 7)) {            
                return (sign == 1) ? INT_MAX : INT_MIN;        
            }
            value = value*10+(str[i]-'0');
            i++;
        }
        return value*sign;
    }
    //字符比较要用"=="，但字符串比较要用equals()方法。
};
