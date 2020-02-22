class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        
        vector<vector<int> > dp(n);
        for(int i=0; i<n; i++){
            dp[i].resize(2);
        }

        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
            dp[i][0] = 0;
            // ½âÊÍ£º
            //   dp[i][0] 
            // = max(dp[-1][0], dp[-1][1] + prices[i])
            // = max(0, -infinity + prices[i]) = 0
            dp[i][1] = -prices[i];
            //½âÊÍ£º
            //   dp[i][1] 
            // = max(dp[-1][1], dp[-1][0] - prices[i])
            // = max(-infinity, 0 - prices[i]) 
            // = -prices[i]
            continue;
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], -prices[i]);
    }
    return dp[n - 1][0];

    }
};
