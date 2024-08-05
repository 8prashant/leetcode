class Solution {
public:
    map<pair<int,int>,int>m;
    int check(int i,vector<int>& nums, int target){
        if(i==0){
            if(target==0){
                if(nums[0]==0){
                    return 2;
                }
                else{
                    return 0;
                }
            }
            else if(nums[0]==abs(target)){
                return 1;
            }
            return 0;
        }
        if(m.find({i,target})!=m.end()){
            return m[{i,target}];
        }
        return m[{i,target}]=check(i-1,nums,target-nums[i])+check(i-1,nums,target+nums[i]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return check(nums.size()-1,nums,target);
    }
};