class Solution {
public:
    vector<string>ans;
    Solution(){
        ans.resize(21);
        ans[1]="0";
        for(int i=2;i<=20;i++){
            string a="";
            for(int j=0;j<ans[i-1].size();j++){
                if(ans[i-1][j]=='0'){
                    a+='1';
                }
                else{
                    a+='0';
                }
            }
            reverse(a.begin(),a.end());
            a=ans[i-1]+'1'+a;
            ans[i]=a;
        }
    }
    char findKthBit(int n, int k) {
        return ans[n][k-1];
    }
};