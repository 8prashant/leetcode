class Solution {
public:
    vector<vector<int>>dp;
    bool p(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int check(int i,int j,string &s){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p(i,j,s)){
            return dp[i][j]=0;
        }
        int ans=INT_MAX;
        for(int l=i+1;l<=j;l++){
            if(p(i,l-1,s)){
                ans=min(ans,1+check(l,j,s));
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return check(0,s.size()-1,s);
    }
};