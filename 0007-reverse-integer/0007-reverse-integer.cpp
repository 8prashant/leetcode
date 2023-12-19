class Solution {
public:
    int reverse(long long int x) {
            long long int neg=0;
            if(x<0){
                x=abs(x);
                neg++;
            }
            long long int n=0;
            while(x!=0){
                if(n>INT_MAX/10 || n==INT_MAX/10 && x%10>7){
                    return 0;
                }
                n=n*10+(x%10);
                x=x/10;
            }
            cout<<n<<endl;
            if(neg>0){
                n=0-n;
                return n;
            }
            else{
                return n;
            }


    }
};