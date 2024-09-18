bool comprator(int a,int b){
    string st1=to_string(a);
    string st2=to_string(b);
    if(st1+st2>st2+st1){
        return true;
    }
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comprator);
        if(nums[0]==0){
            return "0";
        }
        string ans="";
        for(auto x:nums){
            ans+=to_string(x);
        }
        return ans;
    }
};