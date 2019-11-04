class Solution {
public:
    int divide(int dividend, int divisor) {
        long a=labs(dividend);
        long b = labs(divisor);
        long tem = b;
        long result=0;
        long cnt=1;
        while(a>=b){
            cnt=1;
            tem=b;
            while(a>=(tem<<1)){
                tem=tem<<1;
                cnt=cnt<<1;
            }
            a-=tem;
            result+=cnt;
        }
        if((dividend<0) ^(divisor<0)) result=-result;   
        if (result > INT_MAX) result = INT_MAX; // INT_MAX = 2^32 - 1
        return result;
    }
};
