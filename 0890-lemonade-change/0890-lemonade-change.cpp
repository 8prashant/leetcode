class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>v={20,10,5};
        vector<int>m(21,0);
        for(auto x:bills){
            m[x]++;
            int c=x-5;
            if(c==0){
                continue;
            }
            for(int i=0;i<3;i++){
                if(c>=v[i]){
                    int r=c/v[i];
                    c-=v[i]*min(r,m[v[i]]);
                    m[v[i]]-=min(r,m[v[i]]);
                }
            }
            if(c>0){
                return false;
            }
        }
        return true;
    }
};