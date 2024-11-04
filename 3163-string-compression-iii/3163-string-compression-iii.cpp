class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int i=0,j=0;
        while(j<word.size()){
            if(word[i]==word[j] && (j-i)<9){
                j++;
            }
            else{
                int n=j-i;
                ans+=to_string(n);
                ans+=word[i];
                i=j;
            }
        }
        int n=j-i;
        ans+=to_string(n);
        ans+=word[i];
        i=j;
        return ans;
    }
};