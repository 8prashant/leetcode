class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int i;
    KthLargest(int k, vector<int>& nums) {
        i=k;
        for(auto x:nums){
            pq.push(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        for(int i=0;i<pq.size()-i-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */