class Solution {
public:
    int myAtoi(string str) {
        // if (str=="" || str[0]) return 0;
        // string blanks("\f\v\r\t\n ");
        // str.erase(0,str.find_first_not_of(blanks));
        //INT_MAX C++int�����ֵ  INT_MINC++����Сֵ 
        int sign = 1,i=0;
        
        str.erase(0,str.find_first_not_of(" "));//��ȥǰ������пո� 
        if (str=="") return 0;
        if (str[i]== '-' || str[i] == '+')
        sign = str[i++] == '-' ? -1 : 1;
        
        int len = str.length();
        int value = 0;
        while(isdigit(str[i]) && i<len){
            // ���base > MAX_VALUE/10����ôbase*10 + new_value > base*10 > MAX_VALUE����������¾ͻᷢ�������        
            // ��base == INT_MAX/10������new_value = str.charAt(i++) - '0'`����`7`��Ҳ�ᷢ���������ΪMAX_VALUE = 2147483647        
            if (value > INT_MAX/10 || (value == INT_MAX / 10 && str[i] - '0' > 7)) {            
                return (sign == 1) ? INT_MAX : INT_MIN;        
            }
            value = value*10+(str[i]-'0');
            i++;
        }
        return value*sign;
    }
    //�ַ��Ƚ�Ҫ��"=="�����ַ����Ƚ�Ҫ��equals()������
};
