class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis(nums.size(),1);
        vector<int> ris(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    ris[i]=max(ris[i],ris[j]+1);
                }
            }
        }/*
        for(int i=0;i<nums.size();i++){
            cout<<lis[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<nums.size();i++){
            cout<<ris[i]<<" ";
        }
        cout<<endl;*/
        int m = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (lis[i] > 1 && ris[i] > 1) {
                //cout<<"i="<<i<<" ";
                m = max(m, lis[i] + ris[i] - 1);
            }
        }
        //cout<<endl;
        //cout<<"m="<<m<<endl;
        return (nums.size()-m);

    }
};