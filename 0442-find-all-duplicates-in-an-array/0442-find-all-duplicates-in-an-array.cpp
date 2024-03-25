class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size()<2){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<=nums.size()-2;i++){
            cout<<"i="<<i<<endl;
            if(nums[i]==nums[i+1]){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};