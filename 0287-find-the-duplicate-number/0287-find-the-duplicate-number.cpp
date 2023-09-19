class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int key=0,value=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            value=max(value,m[nums[i]]);
            if(value>=2){
                key=nums[i];
                break;
            }
        }
        return key;
    }
};