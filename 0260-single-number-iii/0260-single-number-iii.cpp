class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=0;
        for(auto x:nums){
            n^=x;
        }
        // int lsb=((n^(n-1))&n);
        int lsb=n & -(unsigned int)n;
        int a=0,b=0;
        for(auto x:nums){
            // cout<<x<<" "<<lsb<<endl;
            if((x&lsb)==lsb){
                // cout<<"YES"<<endl;
                a^=x;
            }
            else{
                b^=x;
            }
            // cout<<"a="<<a<<" "<<"b="<<b<<endl;
        }
        return {a,b};
    }
};