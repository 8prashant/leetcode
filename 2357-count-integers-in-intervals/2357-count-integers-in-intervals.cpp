class CountIntervals {
public:
    map<int,int>m;
    long long ans=0;
    CountIntervals() {
    }
    
    void add(int left, int right) {
        auto it=m.lower_bound(left);
        while(it!=m.end() && right>=it->second){
            left=min(left,it->second);
            right=max(right,it->first);
            ans-=(it->first-it->second+1);
            it=m.erase(it);
        }
        ans+=(right-left+1);
        m[right]=left;
    }
    
    long long count() {
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */