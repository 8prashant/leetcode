class Solution {
public:
    map<pair<long long ,long long>,int>m;
    bool dfs(int n,int turn){
        if(n==2){
            return true;
        }
        if(n==1 || n==3){
            return false;
        }
        if(m.find({n,turn})!=m.end()){
            return m[{n,turn}];
        }
        bool ans;
        if(turn==1){
            ans=false;
            for(int i=1;i<n;i++){
                if(n%i==0){
                    ans=ans|| dfs(n-i,turn+1);
                }
            }
        }
        else{
            ans=true;
            for(int i=1;i<n;i++){
                if(n%i==0){
                    ans=ans&& dfs(n-i,turn-1);
                }
            }
        }
        return m[{n,turn}]=ans;
    }
    bool divisorGame(int n) {
        if(n==2){
            return true;
        }
        if(n==1 || n==3){
            return false;
        }
        return dfs(n,1);
    }
};