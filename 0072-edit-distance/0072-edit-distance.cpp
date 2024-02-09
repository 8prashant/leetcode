class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j,string &word1, string &word2){
        if(i<0 && j<0){
            return 0;
        }
        if(i<0 && j>=0){
            return j+1;
        }
        if(j<0 && i>=0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]=dfs(i-1,j-1,word1,word2);
        }
        return dp[i][j]=min({
        1+dfs(i-1,j,word1,word2),
        1+dfs(i,j-1,word1,word2),
        1+dfs(i-1,j-1,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(word2.size()>word1.size()){
            dp.assign(m,vector<int>(n,-1));
            return dfs(m-1,n-1,word2,word1);
        }
        dp.assign(n,vector<int>(m,-1));
        return dfs(n-1,m-1,word1,word2);
    }
};