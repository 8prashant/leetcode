class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int amount, vector<int>& coins,int index){
        if(amount==0){
            return 1;
        }
        if(index==0){
            cout<<"amount="<<amount<<endl;
            if(amount%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int notinc=dfs(amount,coins,index-1);
        int inc=0;
        if(coins[index]<=amount){
            inc=dfs(amount-coins[index],coins,index);
        }
        dp[index][amount]=notinc+inc;
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return dfs(amount,coins,coins.size()-1);
    }
};