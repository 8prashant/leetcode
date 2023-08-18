int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
int keep[1000], vs[1000];

class Solution {
public:
    vector<int>check(vector<int>v){
        vector<int>lis,ans;
        for(int i=0;i<v.size();i++){
            auto li=lower_bound(lis.begin(),lis.end(),v[i]);
            if(li==lis.end()){
                lis.push_back(v[i]);
            }
            else{
                *li=v[i];
            }
            ans.push_back(lis.size());
        }
        return ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>a,b;
        a=check(nums);
        reverse(nums.begin(),nums.end());
        b=check(nums);
        reverse(b.begin(),b.end());
        int ma=0;
        for(int i=0;i<n;i++){
            if(a[i]>1 && b[i]>1){
                ma=max(ma,(a[i]+b[i]-1));
            }
        }
        return n-ma;

    }
};