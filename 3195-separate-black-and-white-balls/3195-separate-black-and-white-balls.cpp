class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int i=s.size()-1,j=s.size()-1;
        while(i>=0){
            while(i>=0 && s[j]!='0'){
                j--;
                i--;
            }
            while(i>=0 && s[i]!='1'){
                i--;
            }
            if(i<0){
                break;
            }
            ans+=j-i;
            swap(s[j],s[i]);
            j--;
            i--;
        }
        return ans;
    }
};