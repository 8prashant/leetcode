public class Solution {
    public int[] PlusOne(int[] digits) {
        int i=digits.Length-1;
        if(digits[i]==9){    
            int count=0;
            while(i>=0 && digits[i]==9){
                count++;
                i--;
            }
            int[] temp;
            if(i<0){
                temp= new int[digits.Length+1];
                i++;
                temp[i]=1;
            }
            else{
                temp= new int[digits.Length];
                Array.Copy(digits,temp,i+1);
                temp[i]++;
            }
            i++;
            for(int j=0;j<count;j++){
                temp[i]=0;
                i++;
            }
            return temp;
        }
        digits[i]++;
        return digits;
    }
}