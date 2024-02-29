class Solution {
public:
    int dfs(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if (buy == 0) {
            int buyStock = -prices[i] + dfs(prices, i + 1, 1, cap, dp);
            int notBuyStock = dfs(prices, i + 1, 0, cap, dp);
            profit = max(buyStock, notBuyStock);
        } else if (buy == 1) {
            int sellStock = prices[i] + dfs(prices, i + 1, 0, cap - 1, dp);
            int notSellStock = dfs(prices, i + 1, 1, cap, dp);
            profit = max(sellStock, notSellStock);
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(prices, 0, 0, 2, dp);
    }
};
