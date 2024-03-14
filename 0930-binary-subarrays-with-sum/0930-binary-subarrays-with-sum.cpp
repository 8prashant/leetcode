class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int count=0;
        int prefsum=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            prefsum+=nums[i];
            int target=prefsum-goal;
            if(m.find(target)!=m.end()){
                count+=m[target];
            }
            m[prefsum]+=1;
        }
        return count;
    }
};