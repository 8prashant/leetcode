//MEMOIZATION

// class Solution {
// public:
    
//     int dfs(string &text1, string &text2, int index1, int index2,vector<vector<int>>&dp) {
//         if (index1 < 0 || index2 < 0) {
//             return 0;
//         }
//         if(dp[index1][index2]!=-1){
//             return dp[index1][index2];
//         }
//         if (text1[index1] == text2[index2]) {
//             return dp[index1][index2]=1 + dfs(text1, text2, index1 - 1, index2 - 1,dp);
//         }
//         return dp[index1][index2]=max(dfs(text1, text2, index1 - 1, index2,dp), dfs(text1, text2, index1, index2 - 1,dp));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size(), m = text2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return dfs(text1, text2, n - 1, m - 1, dp);
//     }
// };

//TABULATION
// class Solution {
// public:
    
//     int dfs(string &text1, string &text2, int index1, int index2,vector<vector<int>>&dp) {
//         if (index1 < 0 || index2 < 0) {
//             return 0;
//         }
//         if(dp[index1][index2]!=-1){
//             return dp[index1][index2];
//         }
//         if (text1[index1] == text2[index2]) {
//             return dp[index1][index2]=1 + dfs(text1, text2, index1 - 1, index2 - 1,dp);
//         }
//         return dp[index1][index2]=max(dfs(text1, text2, index1 - 1, index2,dp), dfs(text1, text2, index1, index2 - 1,dp));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size(), m = text2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return dfs(text1, text2, n - 1, m - 1, dp);
//     }
// };

//SPACE OPTIMIZATION
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1);
            curr[0]=0;
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};