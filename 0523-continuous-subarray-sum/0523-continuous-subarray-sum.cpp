class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%k;
            // cout<<"sum="<<sum<<endl;
            if(m.find(sum)!=m.end()){
                // cout<<"sum="<<sum<<" "<<m[sum]<<" "<<i<<endl;
                if(abs(i-m[sum])>=2){
                    return true;
                }
            }
            else{
                m[sum]=i;
            }
        }
        return false;
    }
};