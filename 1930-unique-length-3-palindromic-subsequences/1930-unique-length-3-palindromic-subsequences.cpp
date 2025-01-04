/*input = abascba

First occurence: a -> 0
                 b -> 1
                 c -> 4
                 s -> 3
Last occurence: a -> 6
                b -> 5
                c -> 4
                s -> 3

Now for each character of them we calculate number of unique characters between both occurences.

For a -> 0 : 6
        unique chars -> a, b, c, s -> 4 answers
For b -> 1 : 5
        unique chars -> a, c, s -> 3 answers
For c -> 4 : 4
        unique chars -> - -> 0 answers
For s -> 5 : 5
        unique chars -> - -> 0 answers

Final asnwer is 4 + 3 + 0 + 0 = 7*/
class Solution {
public:
    //function finds the unique char btw ith and jth postion in string
    int check(int i , int j,string s){
        if(i==j){
            return 0;
        }
        set<char> se;
        for(int k=i+1;k<j;k++){
            se.insert(s[k]);
        }
        return se.size();
    }
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> fo,lo;
        int n=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(fo.find(s[i])==fo.end()){
                fo[s[i]]=i;
            }
            if(lo.find(s[n-i])==lo.end()){
                lo[s[n-i]]=n-i;
            }
        }
        int ans=0;
        for(auto x:fo){
            char c=x.first;
            int i=x.second;
            int j=lo[c];
            int m=check(i,j,s);
            ans+=m;
        }
        return ans;
    }
};