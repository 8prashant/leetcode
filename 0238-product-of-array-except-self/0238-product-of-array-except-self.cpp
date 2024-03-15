class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int pp=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                pp*=nums[i];
            }
            else{
                m[0].push_back(i);
            }
        }
        vector<int> ans(nums.size(),0);
        if(m.find(0)!=m.end()){
            if(m[0].size()>1){
                return ans;
            }
            else{
                ans[m[0][0]]=pp;
                return ans;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=pp/nums[i];
        }
        return ans;
    }
};