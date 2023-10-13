class Solution {
public:
    int ans;
    void check(vector<int>v,int& k,int i){
        int size=v.size()-1;
        if(v.size()==1){
            ans=v[0];
            return;
        }
        else{
            int e=i+k;
            if(e<=size){
                v.erase(v.begin()+e);
                if(e<size){
                    i=e;
                }
                else{
                    i=0;
                }
            }
            else{
                e=e%v.size();
                v.erase(v.begin()+e);
                if(e<size){
                    i=e;
                }
                else{
                    i=0;
                }

            }
            check(v,k,i);
        }
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k-=1;
        check(v,k,0);
        return ans;
    }
};