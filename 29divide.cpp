class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        double a = fabs(dividend);
        double b = fabs(divisor);
        long result = exp(log(a)-log(b));
        if((dividend<0)^(divisor<0)) result=-result;
        if(result>INT_MAX) result=INT_MAX;
        return result;
    }
};
