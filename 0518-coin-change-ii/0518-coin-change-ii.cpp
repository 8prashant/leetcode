class Solution {
public:
    int check(int amount, const vector<int>& coins,int n,vector<vector<int>>&v){
        if(amount==0){
            return 1;
        }
        if(n<=0){
            return 0;
        }
        if(v[amount][n]!=-1){
            return v[amount][n];
        }
        int res=check(amount,coins,n-1,v);
        if(coins[n-1]<=amount){
            res=res+check(amount-coins[n-1],coins,n,v);
        }
        v[amount][n]=res;
        return v[amount][n];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>v(amount+1,vector<int>(coins.size()+1,-1));
        return check(amount,coins,coins.size(),v);
    }
};