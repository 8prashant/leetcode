class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        set<int>s;
        s.insert(0);
        int sum=0;
        int ans=0;
        for(auto x:nums){
            sum+=x;
            if(s.find(sum-k)!=s.end()){
                ans++;
            }
            s.insert(sum);
        }
        return ans;
    }
};