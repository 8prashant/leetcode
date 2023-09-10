/*The Wizard
              _,._      
  .||,       /_ _\\     
 \.`',/      |'L'| |    
 = ,. =      | -,| L    
 / || \    ,-'\"/,'`.   
   ||     ,'   `,,. `.  
   ,|____,' , ,;' \| |  
  (3|\    _/|/'   _| |  
   ||/,-''  | >-'' _,\\ 
   ||'      ==\ ,-'  ,' 
   ||       |  V \ ,|   
   ||       |    |` |   
   ||       |    |   \  
   ||       |    \    \ 
   ||       |     |    \
   ||       |      \_,-'
   ||       |___,,--")_\
   ||         |_|   ccc/
   ||        ccc/       
   ||                hjm
*/
class Solution {
public:
    int check(vector<int>&coins,int n,int amount,vector<vector<int>>&v){
        if(amount==0){
            return 0;
        }
        if(n<=0){
            return INT_MAX;
        }
        if(v[amount][n]!=-1){
            return v[amount][n];
        }


        int c=INT_MAX;
        if(amount>=coins[n-1]){
            c=check(coins,n,amount-coins[n-1],v);
            if(c!=INT_MAX){
                c++;
            }
        }
        int wc=check(coins,n-1,amount,v);
        int res=min(wc,c);
        //cout<<"coin="<<coins[n-1]<<" "<<"amount="<<amount<<" "<<res<<endl;


        if(res==INT_MAX){
            v[amount][n]=INT_MAX;
            return INT_MAX;
        }
        v[amount][n]=res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>v(amount+1,vector<int>(coins.size()+1,-1));
        int ans=check(coins,coins.size(),amount,v);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};