class Solution {
public:
    map<int,int>m;
    void check(int start,int end){
        auto it=m.lower_bound(start);
        while(it!=m.end() && it->second<=end){
            start=min(start,it->second);
            end=max(end,it->first);
            it=m.erase(it);
        }
        m[end]=start;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(auto x:intervals){
            check(x[0],x[1]);
        }
        vector<vector<int>>ans;
        for(auto x:m){
            ans.push_back({x.second,x.first});
        }
        return ans;
    }
};