class Solution {
public:
    vector<vector<int>> dp;
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            dp[i][i] = nums[i];
        }
        for (int len = 1; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                dp[i][j] = max(nums[i] + min((i+2<n)?dp[i + 2][j]:0, (i+1<n && j-1>=0)?dp[i + 1][j - 1]:0),
                            nums[j] + min((i+1<n && j-1>=0)?dp[i + 1][j - 1]:0, (j-2>=0)?dp[i][j - 2]:0));
            }
        }
        int p1 = dp[0][n - 1];
        cout << "p1=" << p1 << endl;
        return (total - p1) <= p1;
    }
};