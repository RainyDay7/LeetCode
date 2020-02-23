class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        int dpi0=0, dpi1=INT_MIN;

        for(int i=0; i<n; i++){
            dpi0=max(dpi0, dpi1+prices[i]);
            dpi1=max(dpi1, -prices[i]);
        }
        return dpi0;

    }
};
