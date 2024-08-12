class KthLargest {
public:
    vector<int>v;
    int i;
    KthLargest(int k, vector<int>& nums) {
        i=k;
        for(auto x:nums){
            v.push_back(x);
        }
    }
    
    int add(int val) {
        v.push_back(val);
        sort(v.begin(),v.end());
        return v[v.size()-i];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */