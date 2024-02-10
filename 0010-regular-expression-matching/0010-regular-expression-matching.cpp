#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    bool dfs(int i, int j, string &s, string &p) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (j < 0) {
            return false;
        }
        if (i < 0) {
            return p[j] == '*' && dfs(i, j - 2, s, p);
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (p[j] != '*' && p[j] != '.') {
            dp[i][j] = s[i] == p[j] && dfs(i - 1, j - 1, s, p);
        } else if (p[j] == '.') {
            dp[i][j] = dfs(i - 1, j - 1, s, p);
        } else {
            dp[i][j] = dfs(i, j - 2, s, p) || ((s[i] == p[j - 1] || p[j - 1] == '.') && dfs(i - 1, j, s, p));
        }
        return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return dfs(n - 1, m - 1, s, p);
    }
};
