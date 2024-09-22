class Solution {
public:
    int strStr(string h, string ne) {
        string st1=ne+"#"+h;
        int n=st1.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(st1[i]==st1[len]){
                lps[i]=len+1;
                if(lps[i]==ne.size()){
                    break;
                }
                i++;
                len++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        if(i==n){
            return -1;
        }
        return (i-(ne.size()-1))-(ne.size()+1);
    }
};