class Solution {
public:
    int ans=0;
    map<int,int>m;
    void check(int start,int end){
        auto it=m.lower_bound(start);
        while(it!=m.end() && end>=it->second){
            start=min(start,it->second);
            end=max(end,it->first);
            ans-=(it->first-it->second+1);
            it=m.erase(it);
        }
        ans+=end-start+1;
        m[end]=start;
    }
    int numberOfPoints(vector<vector<int>>& nums) {
        for(auto x:nums){
            check(x[0],x[1]);
        }
        return ans;
    }
};