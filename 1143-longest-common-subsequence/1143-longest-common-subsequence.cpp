class Solution {
public:
    vector<vector<int>> dp;
    int check(string &t1, string &t2,int i,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(t1[i]==t2[j]){
            return 1+check(t1,t2,i-1,j-1);
        }
        return dp[i][j]=max(check(t1,t2,i-1,j),check(t1,t2,i,j-1));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int i=t1.size()-1;
        int j=t2.size()-1;
        dp.resize(t1.size(),vector<int>(t2.size(),-1));
        return check(t1,t2,i,j);
    }
};