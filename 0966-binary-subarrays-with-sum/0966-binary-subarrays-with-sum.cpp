class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        for(auto x:nums){
            sum+=x;
            if(m.find(sum-goal)!=m.end()){
                ans+=m[sum-goal];
            }
            m[sum]++;
        }
        return ans;
    }
};