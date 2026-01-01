class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        if(digits[i]==9){
            int count=0;
            while(i>=0 && digits[i]==9){
                count++;
                digits.pop_back();
                i--;
            }
            if(i>=0){
                digits[i]++;
            }
            else{
                digits.push_back(1);
            }
            for(int i=0;i<count;i++){
                digits.push_back(0);
            }
            return digits;
        }
        digits[i]++;
        return digits;
    }
};