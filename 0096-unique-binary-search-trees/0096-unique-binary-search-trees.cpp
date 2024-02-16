class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.assign(n+1,0);
        if(n<3){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int j=3;j<=n;j++){
            int ans=0;
            for(int i=1;i<=j;i++){
                int left=dp[i-1];
                int right=dp[j-i];
                if(left>0 && right>0){
                    ans+=(left*right);
                }
                else{
                    ans+=left+right;
                }
            }
            dp[j]=ans;
        }
        return dp[n];
    }
};