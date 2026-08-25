class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0,product=1;
        int k=n;
        while(n){
            long long digit=n%10;
            sum+=digit;
            product*=digit;
            n/=10;
        }

        return k%(sum+product)==0;
    }
};