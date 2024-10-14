class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto x:nums){
            pq.push(x);
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            int a=pq.top();
            pq.pop();
            ans+=a;
            a = ceil(a / 3.0);
            pq.push(a);
        }
        return ans;
    }
};