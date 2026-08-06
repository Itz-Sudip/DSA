class Solution {
public:
    int product(int n){
        int p=1;
        while(n>0){
            int d=(n%10);
            p*=d;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+10;i++){
            if(product(i)%t==0) return i;
        }
        return 0;
    }
};